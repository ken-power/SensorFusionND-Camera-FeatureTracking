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

void DisplayResults(ExperimentResults &results)
{
    const string separator = " | ";

    DisplayPerformanceEvaluation1(results, separator);
    DisplayPerformanceEvaluation2(results, separator);
    DisplayPerformanceEvaluation3(results, separator);
}

void DisplayPerformanceEvaluation1(ExperimentResults &results, const string &separator)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 1 ----------------------\n" << endl;
    cout << "Filename" << separator << "Total Keypoints Detected" << separator << "Time to detect all keypoints (ms)"
         << separator << "Keypoints on Preceding Vehicle" << endl;

    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:| ---:| ---:|" << endl;
    }
    int image = 0;
    for(auto datum:results.data)
    {
        cout << "[" << image << "](" << datum.keypointCount.imageName << ")" << separator << datum.keypointCount.totalKeypoints << separator << datum.keypointCount.descriptorMatchingTime << separator << datum.keypointCount.precedingVehicleKeypoints << endl;
        image++;
    }
}

void DisplayPerformanceEvaluation2(ExperimentResults &results, const string &separator)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 2 ----------------------\n" << endl;
    cout << "Image Pair" << separator << "Total Keypoints Matched" << separator << "KNN Matches" << separator << "Keypoints Removed" << separator << "% Removed" << endl;
    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:| ---:| ---:| ---:|" << endl;
    }
    for(auto datum:results.data)
    {
        cout << datum.keypointMatch.matchedImagePair.second << " --> " << datum.keypointMatch.matchedImagePair.first << separator << datum.keypointMatch.totalMatches << separator << datum.keypointMatch.knnMatches << separator << datum.keypointMatch.removed << separator << datum.keypointMatch.percentageRemoved << endl;
    }

    cout << "\nDisplay just the KNN Matches:\n" << endl;
    cout << "Image Pair" << separator << results.hyperparameters.descriptor << endl;
    unsigned int total = 0;

    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:|" << endl;
    }
    for(auto datum:results.data)
    {
        cout << datum.keypointMatch.matchedImagePair.second << " --> " << datum.keypointMatch.matchedImagePair.first << separator << datum.keypointMatch.totalMatches << endl;
        total += datum.keypointMatch.totalMatches;
    }
    cout << "Total: " << separator << total << endl;
}


void DisplayPerformanceEvaluation3(ExperimentResults &results, const string &separator)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 3 (" << DetectorNameAsString(results.hyperparameters.keypointDetector) << " + " << results.hyperparameters.descriptor << ")----------------------\n" << endl;
    cout << "Image" << separator << "Detection Time (ms)" << separator << "Descriptor Extraction Time (ms)" << endl;
    double totalExtractionTime = 0;
    double totalDetectionTime = 0;
    int image = 0;

    if (separator == " | ") // only needed for markdown table
    {
        cout << ":--- | ---:| ---:|" << endl;
    }
    for(auto datum:results.data)
    {
        cout << "[" << image << "](" << datum.keypointCount.imageName << ")" << separator << datum.keypointCount.descriptorMatchingTime << separator << datum.timing.descriptorExtractionTime << endl;
        totalDetectionTime += datum.keypointCount.descriptorMatchingTime;
        totalExtractionTime += datum.timing.descriptorExtractionTime;
        image++;
    }
    cout << "Totals (ms): " << separator << totalDetectionTime << separator << totalExtractionTime << endl;
}
