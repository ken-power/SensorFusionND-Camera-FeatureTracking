#include "reporting.h"

string DetectorNameAsString(const KeypointDetector detector)
{
    switch (detector)
    {
        case KeypointDetector::Shi_Tomasi:
            return "Shi-Tomasi";
            break;
        case KeypointDetector::HARRIS:
            return "HARRIS";
            break;
        case KeypointDetector::FAST:
            return "FAST";
            break;
        case KeypointDetector::BRISK:
            return "BRISK";
            break;
        case KeypointDetector::ORB:
            return "ORB";
            break;
        case KeypointDetector::AKAZE:
            return "AKAZE";
            break;
        case KeypointDetector::SIFT:
            return "SIFT";
            break;
        default:
            cout << "Not using a specified keypoint detector" << endl;
    }
}

void DisplayResults(Experiment &experiment)
{
    const string separator = " | ";

    DisplayPerformanceEvaluation1(experiment, separator);
    DisplayPerformanceEvaluation2(experiment, separator);
    DisplayPerformanceEvaluation3(experiment, separator);
}

void DisplayPerformanceEvaluation1(Experiment &experiment, const string &separator)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 1 ----------------------\n" << endl;
    cout << "Filename" << separator << "Total Keypoints Detected" << separator << "Time to detect all keypoints (ms)"
         << separator << "Keypoints on Preceding Vehicle" << endl;

    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:| ---:| ---:|" << endl;
    }
    int image = 0;
    for(auto result:experiment.result)
    {
        cout << "[" << image << "](" << result.keypointCount.imageName << ")" << separator << result.keypointCount.totalKeypoints << separator << result.keypointCount.descriptorMatchingTime << separator << result.keypointCount.precedingVehicleKeypoints << endl;
        image++;
    }
}

void DisplayPerformanceEvaluation2(Experiment &experiment, const string &separator)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 2 ----------------------\n" << endl;
    cout << "Image Pair" << separator << "Total Keypoints Matched" << separator << "KNN Matches" << separator << "Keypoints Removed" << separator << "% Removed" << endl;
    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:| ---:| ---:| ---:|" << endl;
    }
    for(auto result:experiment.result)
    {
        cout << result.keypointMatch.matchedImagePair.second << " --> " << result.keypointMatch.matchedImagePair.first << separator << result.keypointMatch.totalMatches << separator << result.keypointMatch.knnMatches << separator << result.keypointMatch.removed << separator << result.keypointMatch.percentageRemoved << endl;
    }

    cout << "\nDisplay just the KNN Matches:\n" << endl;
    cout << "Image Pair" << separator << experiment.hyperparameters.descriptor << endl;
    unsigned int total = 0;

    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:|" << endl;
    }
    for(auto result:experiment.result)
    {
        cout << result.keypointMatch.matchedImagePair.second << " --> " << result.keypointMatch.matchedImagePair.first << separator << result.keypointMatch.totalMatches << endl;
        total += result.keypointMatch.totalMatches;
    }
    cout << "Total: " << separator << total << endl;
}


void DisplayPerformanceEvaluation3(Experiment &experiment, const string &separator)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 3 (" << DetectorNameAsString(experiment.hyperparameters.keypointDetector) << " + " << experiment.hyperparameters.descriptor << ")----------------------\n" << endl;
    cout << "Image" << separator << "Detection Time (ms)" << separator << "Descriptor Extraction Time (ms)" << endl;
    double totalExtractionTime = 0;
    double totalDetectionTime = 0;
    int image = 0;

    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:| ---:|" << endl;
    }
    for(auto result:experiment.result)
    {
        cout << "[" << image << "](" << result.keypointCount.imageName << ")" << separator << result.keypointCount.descriptorMatchingTime << separator << result.descriptorExtractionTime << endl;
        totalDetectionTime += result.keypointCount.descriptorMatchingTime;
        totalExtractionTime += result.descriptorExtractionTime;
        image++;
    }
    cout << "Totals (ms): " << separator << totalDetectionTime << separator << totalExtractionTime << endl;
}
