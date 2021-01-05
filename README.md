# 2D Feature Tracking


# Project Specification

#### Report
Number|Criteria|Meets Specifications|Status
:---:|---|---|---
0|Report|Provide a Writeup / README that includes all the rubric points and how you addressed each one. You can submit your writeup as markdown or pdf.|IN PROGRESS

#### Data Buffer
Number|Criteria|Meets Specifications|Status
:---:|---|---|---
1|Data Buffer Optimization|Implement a vector for dataBuffer objects whose size does not exceed a limit (e.g. 2 elements). This can be achieved by pushing in new elements on one end and removing elements on the other end.|PLANNED

#### Keypoints
Number|Criteria|Meets Specifications|Status
:---:|---|---|---
2|Keypoint Detection|Implement detectors HARRIS, FAST, BRISK, ORB, AKAZE, and SIFT and make them selectable by setting a string accordingly.|PLANNED
3|Keypoint Removal|Remove all keypoints outside of a pre-defined rectangle and only use the keypoints within the rectangle for further processing.|PLANNED

#### Descriptors
Number|Criteria|Meets Specifications|Status
:---:|---|---|---
4|Keypoint Descriptors|Implement descriptors BRIEF, ORB, FREAK, AKAZE and SIFT and make them selectable by setting a string accordingly.|PLANNED
5|Descriptor Matching|Implement FLANN matching as well as k-nearest neighbor selection. Both methods must be selectable using the respective strings in the main function.|PLANNED
6|Descriptor Distance Ratio|Use the K-Nearest-Neighbor matching to implement the descriptor distance ratio test, which looks at the ratio of best vs. second-best match to decide whether to keep an associated pair of keypoints.|PLANNED

#### Performance
Number|Criteria|Meets Specifications|Status
:---:|---|---|---
7|Performance Evaluation 1|Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.|PLANNED
8|Performance Evaluation 2|Count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, the BF approach is used with the descriptor distance ratio set to 0.8.|PLANNED
9|Performance Evaluation 3|Log the time it takes for keypoint detection and descriptor extraction. The results must be entered into a spreadsheet and based on this data, the TOP3 detector / descriptor combinations must be recommended as the best choice for our purpose of detecting keypoints on vehicles.|PLANNED


# Project Report

## 1. Data Buffer

Rather than implement a custom ring buffer, this project is using the Circular Buffer implementation from the Boost C++ libraries. The [references section](#References) contains links to relevant articles to help add Boost to the project. 


## Dependencies for Running Locally
* cmake >= 3.1
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* OpenCV >= 4.5.1
  * This must be compiled from source using the `-D OPENCV_ENABLE_NONFREE=ON` cmake flag for testing the SIFT and SURF detectors.
  * The OpenCV 4.5.1 source code can be found [here](https://github.com/opencv/opencv/tree/4.5.1)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./2D_feature_tracking`.


# References
* Jan Gaspar. [_Chapter 7. Boost.Circular Buffer_](https://www.boost.org/doc/libs/1_61_0/doc/html/circular_buffer.html). [Boost C++ Libraries](https://www.boost.org/).
* Phillip Johnston. [_Creating a Circular Buffer in C and C++_](https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/). [Embedded Artistry](https://embeddedartistry.com/), May 17, 2017.
* StackOverflow. [_How to link C++ program with Boost using CMake_](https://stackoverflow.com/questions/3897839/how-to-link-c-program-with-boost-using-cmake).
