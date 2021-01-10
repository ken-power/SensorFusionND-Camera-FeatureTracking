#ifndef matching2D_hpp
#define matching2D_hpp

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

#include "dataStructures.h"
#include "reporting.h"

void visualizeKeypoints(const vector<cv::KeyPoint> &keypoints, const cv::Mat &img, const string& windowName, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detectKeypoints(cv::Ptr<cv::FeatureDetector> &detector, const std::string& detectorName, std::vector<cv::KeyPoint> &keypoints, const cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detKeypointsSIFT(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detKeypointsAKAZE(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detKeypointsORB(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detKeypointsBRISK(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detKeypointsFAST(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detKeypointsHarris(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void detKeypointsShiTomasi(vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool displayImageWindows, bool saveImageFiles, ExperimentResult &result);
void descKeypoints(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, cv::Mat &descriptors, const std::string& descriptorType, ExperimentResult &result);
void matchDescriptors(vector<cv::KeyPoint> &kPtsSource,
                      vector<cv::KeyPoint> &kPtsRef,
                      cv::Mat &descSource,
                      cv::Mat &descRef,
                      vector<cv::DMatch> &matches,
                      const string &descriptorType,
                      const string& matcherType,
                      const string& selectorType,
                      ExperimentResult &result);

#endif /* matching2D_hpp */
