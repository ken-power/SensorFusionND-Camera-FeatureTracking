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
    KeypointCountResult(){}
    string imageName;
    unsigned int totalKeypoints;
    double descriptorMatchingTime;
    unsigned int precedingVehicleKeypoints;
};

// Performance Evaluation 2
// Count the number of matched keypoints for all 10 images using all possible
// combinations of detectors and descriptors.
struct KeypointMatchResult
{
    KeypointMatchResult(){}
    std::pair<unsigned int, unsigned int> matchedImagePair = {0,0};
    unsigned int totalMatches = 0;
    unsigned int knnMatches = 0;
    unsigned int removed = 0;
    double percentageRemoved = 0.0;
};

struct ExperimentResult
{
    ExperimentResult(){}
    KeypointCountResult keypointCount;
    KeypointMatchResult keypointMatch;

    // Performance Evaluation 3
    // Log the time it takes for keypoint detection and descriptor extraction.
    double descriptorExtractionTime = 0.0;
};

struct Experiment
{
    Experiment(){}
    std::vector<ExperimentResult> result;
    Hyperparameters hyperparameters;
};

struct TotalKeypoints
{
    TotalKeypoints(){}
    unsigned int SHI_TOMASI = 0;
    unsigned int HARRIS = 0;
    unsigned int FAST = 0;
    unsigned int BRISK = 0;
    unsigned int ORB = 0;
    unsigned int AKAZE = 0;
    unsigned int SIFT = 0;
};

struct TotalKeypointMatches
{
    TotalKeypointMatches(){}
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
    AverageProcessingTimes(){}
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
    PerformanceEvaluationSummary(){}
    TotalKeypoints eval1Summary;
    std::vector<TotalKeypointMatches> eval2Summary;
    std::vector<AverageProcessingTimes> eval3Summary;
};


void ProcessExperimentResults(Experiment &experiment, PerformanceEvaluationSummary &summary, bool displayAllResults);
void PerformanceEvaluation1(Experiment &experiment, TotalKeypoints &eval1Summary, const string &separator, bool displayAllResults);
void PerformanceEvaluation2(Experiment &experiment, std::vector<TotalKeypointMatches> &eval2Summary, const string &separator, bool displayAllResults);
void PerformanceEvaluation3(Experiment &experiment, std::vector<AverageProcessingTimes> &eval3Summary, const string &separator, bool displayAllResults);
string DetectorNameAsString(const KeypointDetector detector);

void DisplayPE1Summary(const TotalKeypoints &data);
void DisplayPE2Summary(const std::vector<TotalKeypointMatches> &results);
void DisplayPE3Summary(const std::vector<AverageProcessingTimes> &data);

#endif //CAMERA_FUSION_REPORTING_H
