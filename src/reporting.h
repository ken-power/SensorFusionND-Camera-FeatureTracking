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
    std::pair<unsigned int, unsigned int> matchedImagePair;
    unsigned int totalMatches;
    unsigned int knnMatches;
    unsigned int removed;
    double percentageRemoved;
};

struct ExperimentResult
{
    ExperimentResult(){}
    KeypointCountResult keypointCount;
    KeypointMatchResult keypointMatch;

    // Performance Evaluation 3
    // Log the time it takes for keypoint detection and descriptor extraction.
    double descriptorExtractionTime;
};

struct Experiment
{
    Experiment(){}
    std::vector<ExperimentResult> result;
    Hyperparameters hyperparameters;
};

struct PerfEval1Line
{
    string detector;
    unsigned int totalKeypoints;
};

struct PerfEval2Line
{
    string detector;
    unsigned int totalKeypointMatchesBRISK;
    unsigned int totalKeypointMatchesBRIEF;
    unsigned int totalKeypointMatchesORG;
    unsigned int totalKeypointMatchesFREAK;
    unsigned int totalKeypointMatchesAKAZE;
    unsigned int totalKeypointMatchesSIFT;
};

struct PerfEval3Line
{
    string detector;
    double averageProcessingTimeBRISK;
    double averageProcessingTimeBRIEF;
    double averageProcessingTimeORG;
    double averageProcessingTimeFREAK;
    double averageProcessingTimeAKAZE;
    double averageProcessingTimeSIFT;
};

void ProcessExperimentResults(Experiment &experiment, bool displayAllResults);
void PerformanceEvaluation1(Experiment &experiment, std::vector<PerfEval1Line> &eval1Summary, const string &separator, bool displayAllResults);
void PerformanceEvaluation2(Experiment &experiment, const string &separator, bool displayAllResults);
void PerformanceEvaluation3(Experiment &experiment, const string &separator, bool displayAllResults);
string DetectorNameAsString(const KeypointDetector detector);

#endif //CAMERA_FUSION_REPORTING_H
