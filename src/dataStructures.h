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
    bool visualizeImageMatches = false;
    bool isFocusOnPrecedingVehicleOnly = false;
};


#endif /* dataStructures_h */
