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
            cerr << "Not using a supported keypoint detector" << endl;
    }
}


void ProcessExperimentResults(Experiment &experiment, PerformanceEvaluationSummary &summary, bool displayAllResults)
{
    const string separator = " | ";

    PerformanceEvaluation1(experiment, summary.keypoints, separator, displayAllResults);
    PerformanceEvaluation2(experiment, summary.keypointMatches, separator, displayAllResults);
    PerformanceEvaluation3(experiment, summary.processingTimes, separator, displayAllResults);
}

void DisplayKeypointDetectionSummary(const TotalKeypoints &keypointsData)
{
    cout << "\n## Performance Evaluation 1: Number of Keypoints\n\n" << endl;

    cout << "Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.\n" << endl;

    cout << " Detector | Keypoints on Preceding Vehicle | Total (neighborhood) size" << endl;
    cout << " :--- | ---: | ---:" << endl;

    cout << DetectorNameAsString(Shi_Tomasi) << " | " << keypointsData.SHI_TOMASI << endl;
    cout << DetectorNameAsString(HARRIS) << " | " << keypointsData.HARRIS << endl;
    cout << DetectorNameAsString(FAST) << " | " << keypointsData.FAST << endl;
    cout << DetectorNameAsString(BRISK) << " | " << keypointsData.BRISK << endl;
    cout << DetectorNameAsString(ORB) << " | " << keypointsData.ORB << endl;
    cout << DetectorNameAsString(AKAZE) << " | " << keypointsData.AKAZE << endl;
    cout << DetectorNameAsString(SIFT) << " | " << keypointsData.SIFT << endl;
}

void DisplayKeypointMatchingSummary(const std::vector<TotalKeypointMatches> &keypointMatches)
{
    cout << "\n## Performance Evaluation 2: Number of Matched Keypoints\n" << endl;

    cout << "Count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, the BF approach is used with the descriptor distance ratio set to 0.8.\n" << endl;

    cout << " Detector - Descriptor|" << "BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: | ---: | ---:" << endl;

    for(auto data:keypointMatches)
    {
        cout << data.detector << " | " << data.BRISK << " | " << data.BRIEF << " | " << data.ORB << " | " << data.FREAK << " | " << data.AKAZE << " | " << data.SIFT << endl;
    }
}


void DisplayProcessingTimesSummary(const std::vector<AverageProcessingTimes> &processingTimes)
{
    cout << "\n## Performance Evaluation 3: Keypoint Detection and Descriptor Extraction\n" << endl;

    cout << "Log the time it takes for keypoint detection and descriptor extraction.\n" << endl;

    cout << "\n\n### Keypoint Detection Times\n" << endl;
    cout << " Detector - Descriptor|" << "BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: | ---: | ---:" << endl;

    for(auto data:processingTimes)
    {
        cout << data.detector << " | " << data.detectionTimeBRISK << " | " << data.detectionTimeBRIEF << " | " << data.detectionTimeORB << " | " << data.detectionTimeFREAK << " | " << data.detectionTimeAKAZE << " | " << data.detectionTimeSIFT << endl;
    }


    cout << "\n\n### Descriptor Extraction Times\n" << endl;
    cout << " Detector - Descriptor|" << "BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: | ---: | ---:" << endl;

    for(auto data:processingTimes)
    {
        cout << data.detector << " | " << data.extractionTimeBRISK << " | " << data.extractionTimeBRIEF << " | " << data.extractionTimeORB << " | " << data.extractionTimeFREAK << " | " << data.extractionTimeAKAZE << " | " << data.extractionTimeSIFT << endl;
    }

}


void PerformanceEvaluation1(Experiment &experiment, TotalKeypoints &keypointsData, const string &separator, bool displayAllResults)
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
            keypointsData.SHI_TOMASI = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == HARRIS)
        {
            keypointsData.HARRIS = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == FAST)
        {
            keypointsData.FAST = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == BRISK)
        {
            keypointsData.BRISK = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == ORB)
        {
            keypointsData.ORB = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == AKAZE)
        {
            keypointsData.AKAZE = totalKeypoints;
        }
        else if(experiment.hyperparameters.keypointDetector == SIFT)
        {
            keypointsData.SIFT = totalKeypoints;
        }

        image++;
    }
}

void PerformanceEvaluation2(Experiment &experiment, std::vector<TotalKeypointMatches> &keypointsMatches, const string &separator, bool displayAllResults)
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

    TotalKeypointMatches m;
    int index = 0;

    if (keypointsMatches.size() > 0)
    {
        for (auto element:keypointsMatches)
        {
            if (element.detector == DetectorNameAsString(experiment.hyperparameters.keypointDetector))
            {
                m = element;
                keypointsMatches.erase(keypointsMatches.begin() + index);
                break;
            }
            index++;
        }
    }
    else
    {
        m = TotalKeypointMatches();
    }

    if(experiment.hyperparameters.descriptor == "BRISK")
    {
        m.BRISK = total;
    }
    else if(experiment.hyperparameters.descriptor == "BRIEF")
    {
        m.BRIEF = total;
    }
    else if(experiment.hyperparameters.descriptor == "ORB")
    {
        m.ORB = total;
    }
    else if(experiment.hyperparameters.descriptor == "FREAK")
    {
        m.FREAK = total;
    }
    else if(experiment.hyperparameters.descriptor == "AKAZE")
    {
        m.AKAZE = total;
    }
    else if(experiment.hyperparameters.descriptor == "SIFT")
    {
        m.SIFT = total;
    }

    m.detector = DetectorNameAsString(experiment.hyperparameters.keypointDetector);
    keypointsMatches.push_back(m);
}


void PerformanceEvaluation3(Experiment &experiment, std::vector<AverageProcessingTimes> &processingTimes, const string &separator, bool displayAllResults)
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


    AverageProcessingTimes times;

    int index = 0;

    if (processingTimes.size() > 0)
    {
        for (auto element:processingTimes)
        {
            if (element.detector == DetectorNameAsString(experiment.hyperparameters.keypointDetector))
            {
                times = element;
                processingTimes.erase(processingTimes.begin() + index);
                break;
            }
            index++;
        }
    }
    else
    {
        times = AverageProcessingTimes();
    }


    int divisor = processingTimes.size() > 0 ? processingTimes.size() : 1;

    if(experiment.hyperparameters.descriptor == "BRISK")
    {
        times.detectionTimeBRISK = totalDetectionTime / divisor;
        times.extractionTimeBRISK = totalExtractionTime / divisor;
    }
    else if(experiment.hyperparameters.descriptor == "BRIEF")
    {
        times.detectionTimeBRIEF = totalDetectionTime / divisor;
        times.extractionTimeBRIEF = totalExtractionTime / divisor;
    }
    else if(experiment.hyperparameters.descriptor == "ORB")
    {
        times.detectionTimeORB = totalDetectionTime / divisor;
        times.extractionTimeORB = totalExtractionTime / divisor;
    }
    else if(experiment.hyperparameters.descriptor == "FREAK")
    {
        times.detectionTimeFREAK = totalDetectionTime / divisor;
        times.extractionTimeFREAK = totalExtractionTime / divisor;
    }
    else if(experiment.hyperparameters.descriptor == "AKAZE")
    {
        times.detectionTimeAKAZE = totalDetectionTime / divisor;
        times.extractionTimeAKAZE = totalExtractionTime / divisor;
    }
    else if(experiment.hyperparameters.descriptor == "SIFT")
    {
        times.detectionTimeSIFT = totalDetectionTime / divisor;
        times.extractionTimeSIFT = totalExtractionTime / divisor;
    }

    times.detector = DetectorNameAsString(experiment.hyperparameters.keypointDetector);
    processingTimes.push_back(times);
}
