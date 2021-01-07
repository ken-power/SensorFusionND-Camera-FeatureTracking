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
            cerr << "Not using a specified keypoint detector" << endl;
    }
}


void ProcessExperimentResults(Experiment &experiment, PerformanceEvaluationSummary &summary, bool displayAllResults)
{
    const string separator = " | ";

    PerformanceEvaluation1(experiment, summary.eval1Summary, separator, displayAllResults);
    PerformanceEvaluation2(experiment, separator, displayAllResults);
    PerformanceEvaluation3(experiment, separator, displayAllResults);
}

void DisplayPE1Summary(const TotalKeypoints &data)
{
    cout << "Performance Evaluation 1 Summary Table" << endl;

    cout << " Detector | Keypoints" << endl;
    cout << " :--- | ---:" << endl;

    cout << "SHI_TOMASI" << " | " << data.SHI_TOMASI << endl;
    cout << "HARRIS" << " | " << data.HARRIS << endl;
    cout << "FAST" << " | " << data.FAST << endl;
    cout << "BRISK" << " | " << data.BRISK << endl;
    cout << "ORB" << " | " << data.ORB << endl;
    cout << "AKAZE" << " | " << data.AKAZE << endl;
    cout << "SIFT" << " | " << data.SIFT << endl;
}

void PerformanceEvaluation1(Experiment &experiment, TotalKeypoints &eval1Summary, const string &separator, bool displayAllResults)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 1 ----------------------\n" << endl;

    if(displayAllResults)
        cout << "Filename" << separator << "Total Keypoints Detected" << separator << "Time to detect all keypoints (ms)"
             << separator << "Keypoints on Preceding Vehicle" << endl;

    if (separator == " | ") // only needed for markdown table
    {
        if(displayAllResults)
            cout << ":--- | ---:| ---:| ---:|" << endl;
    }
    unsigned int image = 0;
    unsigned int totalKeypoints = 0;

    for(auto result:experiment.result)
    {
        if(displayAllResults)
            cout << "[" << image << "](" << result.keypointCount.imageName << ")" << separator << result.keypointCount.totalKeypoints << separator << result.keypointCount.descriptorMatchingTime << separator << result.keypointCount.precedingVehicleKeypoints << endl;

        totalKeypoints += result.keypointCount.totalKeypoints;

        if(experiment.hyperparameters.keypointDetector == Shi_Tomasi)
        {
            eval1Summary.SHI_TOMASI = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == HARRIS)
        {
            eval1Summary.HARRIS = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == FAST)
        {
            eval1Summary.FAST = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == BRISK)
        {
            eval1Summary.BRISK = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == ORB)
        {
            eval1Summary.ORB = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == AKAZE)
        {
            eval1Summary.AKAZE = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == SIFT)
        {
            eval1Summary.SIFT = totalKeypoints;
        }

        image++;
    }
}

void PerformanceEvaluation2(Experiment &experiment, const string &separator, bool displayAllResults)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 2 ----------------------\n" << endl;

    if(displayAllResults)
        cout << "Image Pair" << separator << "Total Keypoints Matched" << separator << "KNN Matches" << separator << "Keypoints Removed" << separator << "% Removed" << endl;

    if (separator == " | ") // only needed for markdown table
    {
        if(displayAllResults)
            cout << ":--- | ---:| ---:| ---:| ---:|" << endl;
    }
    for(auto result:experiment.result)
    {
        if(displayAllResults)
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


void PerformanceEvaluation3(Experiment &experiment, const string &separator, bool displayAllResults)
{
    cout << "\n\n\n ------------- RESULTS: Performance Evaluation 3 (" << DetectorNameAsString(experiment.hyperparameters.keypointDetector) << " + " << experiment.hyperparameters.descriptor << ")----------------------\n" << endl;

    if(displayAllResults)
        cout << "Image" << separator << "Detection Time (ms)" << separator << "Descriptor Extraction Time (ms)" << endl;

    double totalExtractionTime = 0;
    double totalDetectionTime = 0;
    int image = 0;

    if (separator == " | ") // only needed for markdown table
    {
        if(displayAllResults)
            cout << ":--- | ---:| ---:|" << endl;
    }
    for(auto result:experiment.result)
    {
        if(displayAllResults)
            cout << "[" << image << "](" << result.keypointCount.imageName << ")" << separator << result.keypointCount.descriptorMatchingTime << separator << result.descriptorExtractionTime << endl;
        totalDetectionTime += result.keypointCount.descriptorMatchingTime;
        totalExtractionTime += result.descriptorExtractionTime;
        image++;
    }
    if(displayAllResults)
        cout << "Totals (ms): " << separator << totalDetectionTime << separator << totalExtractionTime << endl;
}
