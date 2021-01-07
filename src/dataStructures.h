#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <opencv2/core.hpp>

using namespace std;

struct DataFrame { // represents the available sensor information at the same time instance
    
    cv::Mat cameraImg; // camera image
    
    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> keypointMatches; // keypoint matches between previous and current frame
};

enum KeypointDetector
{
    Shi_Tomasi,
    HARRIS,
    FAST,
    BRISK,
    ORB,
    AKAZE,
    SIFT
};

struct Hyperparameters
{
    Hyperparameters(){}

    KeypointDetector keypointDetector;
    string descriptor;
    string matcherType;
    string descriptorType;
    string selectorType;
};

// Performance Evaluation 1
// Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution
// of their neighborhood size. Do this for all the detectors you have implemented.
struct KeypointCountResult
{
    KeypointCountResult(){}
    string imageName;
    unsigned int numberOfKeypoints;
    double matchTiming;
};

// Performance Evaluation 2
// Count the number of matched keypoints for all 10 images using all possible
// combinations of detectors and descriptors.
struct KeypointMatchResult
{
    KeypointMatchResult(){}
    std::pair<string, string> matchedImagePair;
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
    std::pair<string, string> matchedImagePair;
    double detectionTime;
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
    std::vector<ExperimentResultLine> results;
    Hyperparameters hyperparameters;
};

#endif /* dataStructures_h */
