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


void ProcessExperimentResults(Experiment &experiment, PerformanceEvaluationSummary &summary)
{
    const string separator = " | ";

    PerformanceEvaluation1(experiment, summary.keypoints, separator);
    PerformanceEvaluation2(experiment, summary.keypointMatches, separator);
    PerformanceEvaluation3(experiment, summary.processingTimes, separator);
}

void DisplayKeypointDetectionSummary(const TotalKeypoints &keypointsData)
{
    const unsigned int numberOfImages = 10;
    const string separator = " | ";

    cout << "\n## Performance Evaluation 1: Number of Keypoints\n\n" << endl;

    cout << "Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.\n" << endl;

    cout << " Detector " << separator << "Total keypoints from all " << numberOfImages <<  " images " << separator << "Total keypoints in scene (average per image)" << separator << "Keypoints detected on preceding vehicle (average per image)" << separator << "% keypoints removed from scene to focus on preceding vehicle" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: " << endl;

    cout << DetectorNameAsString(Shi_Tomasi) << separator << keypointsData.SHI_TOMASI_totalKeypointsInImage << separator << keypointsData.SHI_TOMASI_totalKeypointsInImage / numberOfImages << separator << keypointsData.SHI_TOMASI_totalKeypointsOnPrecedingVehicle / numberOfImages << separator  << 100 - keypointsData.SHI_TOMASI_percentageRepresentedByVehicleKeypoints << endl;
    cout << DetectorNameAsString(HARRIS) << separator << keypointsData.HARRIS_totalKeypointsInImage << separator << keypointsData.HARRIS_totalKeypointsInImage / numberOfImages << separator << keypointsData.HARRIS_totalKeypointsOnPrecedingVehicle / numberOfImages << separator  << 100 - keypointsData.HARRIS_percentageRepresentedByVehicleKeypoints << endl;
    cout << DetectorNameAsString(FAST) << separator << keypointsData.FAST_totalKeypointsInImage << separator << keypointsData.FAST_totalKeypointsInImage / numberOfImages << separator << keypointsData.FAST_totalKeypointsOnPrecedingVehicle / numberOfImages << separator <<  100 - keypointsData.FAST_percentageRepresentedByVehicleKeypoints << endl;
    cout << DetectorNameAsString(BRISK) << separator << keypointsData.BRISK_totalKeypointsInImage << separator << keypointsData.BRISK_totalKeypointsInImage / numberOfImages << separator << keypointsData.BRISK_totalKeypointsOnPrecedingVehicle / numberOfImages << separator  << 100 - keypointsData.BRISK_percentageRepresentedByVehicleKeypoints << endl;
    cout << DetectorNameAsString(ORB) << separator << keypointsData.ORB_totalKeypointsInImage << separator << keypointsData.ORB_totalKeypointsInImage / numberOfImages << separator << keypointsData.ORB_totalKeypointsOnPrecedingVehicle / numberOfImages << separator  << 100 - keypointsData.ORB_percentageRepresentedByVehicleKeypoints << endl;
    cout << DetectorNameAsString(AKAZE) << separator << keypointsData.AKAZE_totalKeypointsInImage << separator << keypointsData.AKAZE_totalKeypointsInImage / numberOfImages << separator << keypointsData.AKAZE_totalKeypointsOnPrecedingVehicle / numberOfImages << separator << 100 - keypointsData.AKAZE_percentageRepresentedByVehicleKeypoints << endl;
    cout << DetectorNameAsString(SIFT) << separator << keypointsData.SIFT_totalKeypointsInImage << separator << keypointsData.SIFT_totalKeypointsInImage / numberOfImages << separator << keypointsData.SIFT_totalKeypointsOnPrecedingVehicle / numberOfImages << separator  << 100 - keypointsData.SIFT_percentageRepresentedByVehicleKeypoints << endl;
}

void DisplayKeypointMatchingSummary(const std::vector<TotalKeypointMatches> &keypointMatches)
{
    cout << "\n## Performance Evaluation 2: Number of Matched Keypoints\n" << endl;

    cout << "Count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, the BF approach is used with the descriptor distance ratio set to 0.8.\n" << endl;

    cout << "### Total number of matched keypoints over 10 images" << endl;
    cout << " Detector - Descriptor|" << "BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: | ---: | ---:" << endl;

    for(const auto& data:keypointMatches)
    {
        cout << data.detector << " | " << data.BRISK << " | " << data.BRIEF << " | " << data.ORB << " | " << data.FREAK << " | " << data.AKAZE << " | " << data.SIFT << endl;
    }

    const int numberOfImages = 10;
    cout << "### Average number of matched keypoints per image pair" << endl;
    cout << " Detector - Descriptor|" << "BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: | ---: | ---:" << endl;

    for(const auto& data:keypointMatches)
    {
        cout << data.detector << " | " << data.BRISK / numberOfImages << " | " << data.BRIEF / numberOfImages << " | " << data.ORB / numberOfImages << " | " << data.FREAK / numberOfImages << " | " << data.AKAZE / numberOfImages << " | " << data.SIFT / numberOfImages << endl;
    }
}


void DisplayProcessingTimesSummary(const std::vector<AverageProcessingTimes> &processingTimes)
{
    cout << "\n## Performance Evaluation 3: Keypoint Detection and Descriptor Extraction\n" << endl;

    cout << "Log the time it takes for keypoint detection and descriptor extraction.\n" << endl;

    cout << "\n\n### Keypoint Detection Times (milliseconds)\n" << endl;
    cout << " Detector - Descriptor|" << "BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: | ---: | ---:" << endl;

    for(const auto& data:processingTimes)
    {
        cout << data.detector << " | " << data.detectionTimeBRISK << " | " << data.detectionTimeBRIEF << " | " << data.detectionTimeORB << " | " << data.detectionTimeFREAK << " | " << data.detectionTimeAKAZE << " | " << data.detectionTimeSIFT << endl;
    }


    cout << "\n\n### Descriptor Extraction Times (milliseconds)\n" << endl;
    cout << " Detector - Descriptor|" << "BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT" << endl;
    cout << " :--- | ---: | ---: | ---: | ---: | ---: | ---:" << endl;

    for(const auto& data:processingTimes)
    {
        cout << data.detector << " | " << data.extractionTimeBRISK << " | " << data.extractionTimeBRIEF << " | " << data.extractionTimeORB << " | " << data.extractionTimeFREAK << " | " << data.extractionTimeAKAZE << " | " << data.extractionTimeSIFT << endl;
    }

}


void PerformanceEvaluation1(Experiment &experiment, TotalKeypoints &keypointsData, const string &separator)
{
    cout << "---- Processing Performance Evaluation 1: Keypoint count data (" << DetectorNameAsString(experiment.hyperparameters.keypointDetector) << " + " << experiment.hyperparameters.descriptor << ")" << endl;

    unsigned int image = 0;
    unsigned int totalKeypointsInImage = 0;
    unsigned int totalKeypointsOnPrecedingVehicle = 0;

    for(const auto& result:experiment.result)
    {
        totalKeypointsInImage += result.keypointCount.totalKeypoints;
        totalKeypointsOnPrecedingVehicle += result.keypointCount.precedingVehicleKeypoints;

        if(experiment.hyperparameters.keypointDetector == Shi_Tomasi)
        {
            keypointsData.SHI_TOMASI_totalKeypointsInImage = totalKeypointsInImage;
            keypointsData.SHI_TOMASI_totalKeypointsOnPrecedingVehicle = totalKeypointsOnPrecedingVehicle;
            keypointsData.SHI_TOMASI_percentageRepresentedByVehicleKeypoints = (static_cast<double>(totalKeypointsOnPrecedingVehicle) / static_cast<double>(totalKeypointsInImage))*100;
        }
        else if(experiment.hyperparameters.keypointDetector == HARRIS)
        {
            keypointsData.HARRIS_totalKeypointsInImage = totalKeypointsInImage;
            keypointsData.HARRIS_totalKeypointsOnPrecedingVehicle = totalKeypointsOnPrecedingVehicle;
            keypointsData.HARRIS_percentageRepresentedByVehicleKeypoints = (static_cast<double>(totalKeypointsOnPrecedingVehicle) / static_cast<double>(totalKeypointsInImage))*100;
        }
        else if(experiment.hyperparameters.keypointDetector == FAST)
        {
            keypointsData.FAST_totalKeypointsInImage = totalKeypointsInImage;
            keypointsData.FAST_totalKeypointsOnPrecedingVehicle = totalKeypointsOnPrecedingVehicle;
            keypointsData.FAST_percentageRepresentedByVehicleKeypoints = (static_cast<double>(totalKeypointsOnPrecedingVehicle) / static_cast<double>(totalKeypointsInImage))*100;
        }
        else if(experiment.hyperparameters.keypointDetector == BRISK)
        {
            keypointsData.BRISK_totalKeypointsInImage = totalKeypointsInImage;
            keypointsData.BRISK_totalKeypointsOnPrecedingVehicle = totalKeypointsOnPrecedingVehicle;
            keypointsData.BRISK_percentageRepresentedByVehicleKeypoints = (static_cast<double>(totalKeypointsOnPrecedingVehicle) / static_cast<double>(totalKeypointsInImage))*100;
        }
        else if(experiment.hyperparameters.keypointDetector == ORB)
        {
            keypointsData.ORB_totalKeypointsInImage = totalKeypointsInImage;
            keypointsData.ORB_totalKeypointsOnPrecedingVehicle = totalKeypointsOnPrecedingVehicle;
            keypointsData.ORB_percentageRepresentedByVehicleKeypoints = (static_cast<double>(totalKeypointsOnPrecedingVehicle) / static_cast<double>(totalKeypointsInImage))*100;
        }
        else if(experiment.hyperparameters.keypointDetector == AKAZE)
        {
            keypointsData.AKAZE_totalKeypointsInImage = totalKeypointsInImage;
            keypointsData.AKAZE_totalKeypointsOnPrecedingVehicle = totalKeypointsOnPrecedingVehicle;
            keypointsData.AKAZE_percentageRepresentedByVehicleKeypoints = (static_cast<double>(totalKeypointsOnPrecedingVehicle) / static_cast<double>(totalKeypointsInImage))*100;
        }
        else if(experiment.hyperparameters.keypointDetector == SIFT)
        {
            keypointsData.SIFT_totalKeypointsInImage = totalKeypointsInImage;
            keypointsData.SIFT_totalKeypointsOnPrecedingVehicle = totalKeypointsOnPrecedingVehicle;
            keypointsData.SIFT_percentageRepresentedByVehicleKeypoints = (static_cast<double>(totalKeypointsOnPrecedingVehicle) / static_cast<double>(totalKeypointsInImage))*100;
        }

        image++;
    }
}

void PerformanceEvaluation2(Experiment &experiment,
                            std::vector<TotalKeypointMatches> &keypointsMatches,
                            const string &separator)
{
    cout << "---- Processing Performance Evaluation 2: Keypoints matches data (" << DetectorNameAsString(experiment.hyperparameters.keypointDetector) << " + " << experiment.hyperparameters.descriptor << ")" << endl;

    unsigned int totalMatches = 0;

    for(const auto& result:experiment.result)
    {
        totalMatches += result.keypointMatch.totalMatches;
    }

    TotalKeypointMatches keypointMatches;
    int index = 0;

    if (!keypointsMatches.empty())
    {
        for (const auto& element:keypointsMatches)
        {
            if (element.detector == DetectorNameAsString(experiment.hyperparameters.keypointDetector))
            {
                keypointMatches = element;
                keypointsMatches.erase(keypointsMatches.begin() + index);
                break;
            }
            index++;
        }
    }
    else
    {
        keypointMatches = TotalKeypointMatches();
    }

    if(experiment.hyperparameters.descriptor == "BRISK")
    {
        keypointMatches.BRISK = totalMatches;
    }
    else if(experiment.hyperparameters.descriptor == "BRIEF")
    {
        keypointMatches.BRIEF = totalMatches;
    }
    else if(experiment.hyperparameters.descriptor == "ORB")
    {
        keypointMatches.ORB = totalMatches;
    }
    else if(experiment.hyperparameters.descriptor == "FREAK")
    {
        keypointMatches.FREAK = totalMatches;
    }
    else if(experiment.hyperparameters.descriptor == "AKAZE")
    {
        keypointMatches.AKAZE = totalMatches;
    }
    else if(experiment.hyperparameters.descriptor == "SIFT")
    {
        keypointMatches.SIFT = totalMatches;
    }

    keypointMatches.detector = DetectorNameAsString(experiment.hyperparameters.keypointDetector);
    keypointsMatches.push_back(keypointMatches);
}


void PerformanceEvaluation3(Experiment &experiment,
                            std::vector<AverageProcessingTimes> &processingTimes,
                            const string &separator)
{
    cout << "---- Processing Performance Evaluation 3: processing times for descriptor matching and extraction (" << DetectorNameAsString(experiment.hyperparameters.keypointDetector) << " + " << experiment.hyperparameters.descriptor << ")" << endl;

    double totalExtractionTime = 0;
    double totalDetectionTime = 0;
    int image = 0;

    for(const auto& result:experiment.result)
    {
        totalDetectionTime += result.keypointCount.descriptorMatchingTime;
        totalExtractionTime += result.descriptorExtractionTime;
        image++;
    }

    AverageProcessingTimes times;

    int index = 0;

    if (!processingTimes.empty())
    {
        for (const auto& element:processingTimes)
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


    int divisor = !processingTimes.empty() ? processingTimes.size() : 1;

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


void DisplayKeypointDetectionImages()
{
    string dir = "results/images/keypoint_detections/";

    cout << "### Keypoints detected by each detector" << endl;
    cout << "#### Shi-Tomasi" << endl << "![](" + dir + "Shi_Tomasi_Corner_Detection_Results.png)" << endl;
    cout << "#### Harris" << endl << "![](" + dir + "Harris_Corner_Detection_Results.png)" << endl;
    cout << "#### FAST" << endl << "![](" + dir + "FAST_Keypoint_Detection_Results.png)" << endl;
    cout << "#### SIFT" << endl << "![](" + dir + "SIFT_Keypoint_Detection_Results.png)" << endl;
    cout << "#### AKAZE" << endl << "![](" + dir + "AKAZE_Keypoint_Detection_Results.png)" << endl;
    cout << "#### ORB" << endl << "![](" + dir + "ORB_Keypoint_Detection_Results.png)" << endl;
    cout << "#### BRISK" << endl << "![](" + dir + "BRISK_Keypoint_Detection_Results.png)" << endl;
}

void DisplayKeypointMatchImages(const std::vector<KeypointDetector> &detectors, const std::vector<string> &descriptors)
{
    string dir = "results/images/keypoint_matches/";
    unsigned int imagePair = 4;

    cout << "## Examples of keypoint matches detected by each detector-descriptor pair" << endl;

    for(const auto &detector:detectors)
    {
        cout << "###" << DetectorNameAsString(detector) << endl ;

        for(const auto &descriptor:descriptors)
        {
            cout << "####" << DetectorNameAsString(detector) << " + " << descriptor << " showing matches between image " << to_string(imagePair-1) << " and image " << to_string(imagePair) << endl;
            cout << "![](" + dir + DetectorNameAsString(detector) + "_" + descriptor + "_" + to_string(imagePair) + ".png)" << endl;
        }
    }
}
