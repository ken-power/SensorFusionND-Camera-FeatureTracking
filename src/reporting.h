#ifndef CAMERA_FUSION_REPORTING_H
#define CAMERA_FUSION_REPORTING_H

#include <iostream>
#include "dataStructures.h"

using namespace std;


// Performance Evaluation 1
// Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution
// of their neighborhood size. Do this for all the detectors you have implemented.
struct KeypointCountResult
{
    KeypointCountResult()= default;
    string imageName = "No image name specified";
    unsigned int totalKeypoints = 0;
    double descriptorMatchingTime = 0.0;
    unsigned int precedingVehicleKeypoints = 0;
};

// Performance Evaluation 2
// Count the number of matched keypoints for all 10 images using all possible
// combinations of detectors and descriptors.
struct KeypointMatchResult
{
    KeypointMatchResult()= default;
    std::pair<unsigned int, unsigned int> matchedImagePair = {0,0};
    unsigned int totalMatches = 0;
    unsigned int knnMatches = 0;
    unsigned int removed = 0;
    double percentageRemoved = 0.0;
};

struct ExperimentResult
{
    ExperimentResult()= default;
    KeypointCountResult keypointCount;
    KeypointMatchResult keypointMatch;

    // Performance Evaluation 3
    // Log the time it takes for keypoint detection and descriptor extraction.
    double descriptorExtractionTime = 0.0;
};

struct Experiment
{
    Experiment()= default;
    std::vector<ExperimentResult> result;
    Hyperparameters hyperparameters;
};

struct TotalKeypoints
{
    TotalKeypoints()= default;
    unsigned int SHI_TOMASI_totalKeypointsInImage = 0;
    unsigned int HARRIS_totalKeypointsInImage = 0;
    unsigned int FAST_totalKeypointsInImage = 0;
    unsigned int BRISK_totalKeypointsInImage = 0;
    unsigned int ORB_totalKeypointsInImage = 0;
    unsigned int AKAZE_totalKeypointsInImage = 0;
    unsigned int SIFT_totalKeypointsInImage = 0;

    unsigned int SHI_TOMASI_totalKeypointsOnPrecedingVehicle = 0;
    unsigned int HARRIS_totalKeypointsOnPrecedingVehicle = 0;
    unsigned int FAST_totalKeypointsOnPrecedingVehicle = 0;
    unsigned int BRISK_totalKeypointsOnPrecedingVehicle = 0;
    unsigned int ORB_totalKeypointsOnPrecedingVehicle = 0;
    unsigned int AKAZE_totalKeypointsOnPrecedingVehicle = 0;
    unsigned int SIFT_totalKeypointsOnPrecedingVehicle = 0;

    double SHI_TOMASI_percentageRepresentedByVehicleKeypoints = 0.0;
    double HARRIS_percentageRepresentedByVehicleKeypoints = 0.0;
    double FAST_percentageRepresentedByVehicleKeypoints = 0.0;
    double BRISK_percentageRepresentedByVehicleKeypoints = 0.0;
    double ORB_percentageRepresentedByVehicleKeypoints = 0.0;
    double AKAZE_percentageRepresentedByVehicleKeypoints = 0.0;
    double SIFT_percentageRepresentedByVehicleKeypoints = 0.0;
};

struct TotalKeypointMatches
{
    TotalKeypointMatches()= default;
    string detector;
    unsigned int BRISK = 0;
    unsigned int BRIEF = 0;
    unsigned int ORB = 0;
    unsigned int FREAK = 0;
    unsigned int AKAZE = 0;
    unsigned int SIFT = 0;
};

struct AverageProcessingTimes
{
    AverageProcessingTimes()= default;
    string detector;
    double detectionTimeBRISK = 0.0;
    double detectionTimeBRIEF = 0.0;
    double detectionTimeORB = 0.0;
    double detectionTimeFREAK = 0.0;
    double detectionTimeAKAZE = 0.0;
    double detectionTimeSIFT = 0.0;

    double extractionTimeBRISK = 0.0;
    double extractionTimeBRIEF = 0.0;
    double extractionTimeORB = 0.0;
    double extractionTimeFREAK = 0.0;
    double extractionTimeAKAZE = 0.0;
    double extractionTimeSIFT = 0.0;
};


struct PerformanceEvaluationSummary
{
    PerformanceEvaluationSummary()= default;
    TotalKeypoints keypoints;
    std::vector<TotalKeypointMatches> keypointMatches;
    std::vector<AverageProcessingTimes> processingTimes;
};


void ProcessExperimentResults(Experiment &experiment, PerformanceEvaluationSummary &summary);
void PerformanceEvaluation1(Experiment &experiment, TotalKeypoints &keypointsData, const string &separator);
void PerformanceEvaluation2(Experiment &experiment,
                            std::vector<TotalKeypointMatches> &keypointsMatches,
                            const string &separator);
void PerformanceEvaluation3(Experiment &experiment,
                            std::vector<AverageProcessingTimes> &processingTimes,
                            const string &separator);
string DetectorNameAsString(const KeypointDetector detector);

void DisplayKeypointDetectionSummary(const TotalKeypoints &keypointsData);
void DisplayKeypointMatchingSummary(const std::vector<TotalKeypointMatches> &keypointMatches);
void DisplayProcessingTimesSummary(const std::vector<AverageProcessingTimes> &processingTimes);
void DisplayKeypointDetectionImages();
void DisplayKeypointMatchImages(const std::vector<KeypointDetector> &detectors, const std::vector<string> &descriptors);

#endif //CAMERA_FUSION_REPORTING_H
