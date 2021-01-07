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

// Performance Evaluation 3
// Log the time it takes for keypoint detection and descriptor extraction.
struct TimingResult
{
    TimingResult(){}
    double descriptorExtractionTime;
};

struct ExperimentResultLine
{
    ExperimentResultLine(){}
    KeypointCountResult keypointCount;
    KeypointMatchResult keypointMatch;
    TimingResult timing;
};

struct ExperimentResults
{
    ExperimentResults(){}
    std::vector<ExperimentResultLine> data;
    Hyperparameters hyperparameters;
};


void DisplayResults(ExperimentResults &results);
void DisplayPerformanceEvaluation1(ExperimentResults &results, const string &separator);
void DisplayPerformanceEvaluation2(ExperimentResults &results, const string &separator);
void DisplayPerformanceEvaluation3(ExperimentResults &results, const string &separator);
string DetectorNameAsString(const KeypointDetector detector);

#endif //CAMERA_FUSION_REPORTING_H
