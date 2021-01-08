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

    KeypointDetector keypointDetector = Shi_Tomasi;
    string descriptor = "BRIEF";                    // BRISK, BRIEF, ORB, FREAK, AKAZE, SIFT
    string matcherType = "MAT_BF";                  // MAT_BF, MAT_FLANN
    string descriptorType = "DES_BINARY";           // DES_BINARY, DES_HOG
    string selectorType = "SEL_KNN";                // SEL_NN, SEL_KNN
    bool visualizeImageMatches = false;             // visualize matches between current and previous image?
    bool isFocusOnPrecedingVehicleOnly = true;      // only keep keypoints on the preceding vehicle?
};


#endif /* dataStructures_h */
