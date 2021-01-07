#ifndef matching2D_hpp
#define matching2D_hpp

#include <stdio.h>
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

void visualizeKeypoints(const std::vector<cv::KeyPoint> &keypoints, const cv::Mat &img, const std::string windowName, ExperimentResultLine &results);
void detectKeypoints(cv::Ptr<cv::FeatureDetector> &detector, std::string detectorName, std::vector<cv::KeyPoint> &keypoints, const cv::Mat &img, bool bVis, ExperimentResultLine &results);

void detKeypointsSIFT(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool bVis, ExperimentResultLine &results);
void detKeypointsAKAZE(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool bVis, ExperimentResultLine &results);
void detKeypointsORB(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool bVis, ExperimentResultLine &results);
void detKeypointsBRISK(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool bVis, ExperimentResultLine &results);
void detKeypointsFAST(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool bVis, ExperimentResultLine &results);
void detKeypointsHarris(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool bVis, ExperimentResultLine &results);
void detKeypointsShiTomasi(vector<cv::KeyPoint> &keypoints, cv::Mat &img, bool bVis, ExperimentResultLine &results);
void detKeypointsModern(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, std::string detectorType, bool bVis, ExperimentResultLine &results);
void descKeypoints(std::vector<cv::KeyPoint> &keypoints, cv::Mat &img, cv::Mat &descriptors, std::string descriptorType, ExperimentResultLine &results);
void matchDescriptors(vector<cv::KeyPoint> &kPtsSource,
                      vector<cv::KeyPoint> &kPtsRef,
                      cv::Mat &descSource,
                      cv::Mat &descRef,
                      vector<cv::DMatch> &matches,
                      string descriptorType,
                      string matcherType,
                      string selectorType,
                      ExperimentResultLine &results);

#endif /* matching2D_hpp */
