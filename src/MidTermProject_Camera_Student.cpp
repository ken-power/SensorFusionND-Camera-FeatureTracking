/* INCLUDES FOR THIS PROJECT */
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>

#include <boost/circular_buffer.hpp>

#include "dataStructures.h"
#include "matching2D.hpp"

using namespace std;

/* MAIN PROGRAM */
int main(int argc, const char *argv[])
{

    /* INIT VARIABLES AND DATA STRUCTURES */

    // data location
    string dataPath = "../";

    // camera
    string imgBasePath = dataPath + "images/";
    string imgPrefix = "KITTI/2011_09_26/image_00/data/000000"; // left camera, color
    string imgFileType = ".png";
    int imgStartIndex = 0; // first file index to load (assumes Lidar and camera names have identical naming convention)
    int imgEndIndex = 9;   // last file index to load
    int imgFillWidth = 4;  // no. of digits which make up the file index (e.g. img-0001.png)

    // misc
    int dataBufferSize = 2;       // no. of images which are held in memory (ring buffer) at the same time
    boost::circular_buffer<DataFrame> dataBuffer(dataBufferSize); // buffer of data frames which are held in memory at the same time
    //vector<DataFrame> dataBuffer; // list of data frames which are held in memory at the same time
    bool bVis = false;            // visualize results

    /* MAIN LOOP OVER ALL IMAGES */

    for (size_t imgIndex = 0; imgIndex <= imgEndIndex - imgStartIndex; imgIndex++)
    {
        /* LOAD IMAGE INTO BUFFER */

        // assemble filenames for current index
        ostringstream imgNumber;
        imgNumber << setfill('0') << setw(imgFillWidth) << imgStartIndex + imgIndex;
        string imgFullFilename = imgBasePath + imgPrefix + imgNumber.str() + imgFileType;

        // load image from file and convert to grayscale
        cv::Mat img, imgGray;
        img = cv::imread(imgFullFilename);
        cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

        //// STUDENT ASSIGNMENT
        //// TASK MP.1 -> replace the following code with ring buffer of size dataBufferSize

        // push image into data frame buffer
        DataFrame frame; // instantiate the dataframe
        frame.cameraImg = imgGray; // add the image to the dataframe
        dataBuffer.push_back(frame); // push the dataframe onto the data buffer

        //// EOF STUDENT ASSIGNMENT
        cout << "------>>>> Data Buffer Size = " << dataBuffer.size() << "    <<<<------" << endl;
        cout << "#1 : LOAD IMAGE INTO BUFFER done" << endl;

        /* DETECT IMAGE KEYPOINTS */

        // extract 2D keypoints from current image
        vector<cv::KeyPoint> keypoints; // create empty feature list for current image

        //// STUDENT ASSIGNMENT
        //// TASK MP.2 -> add the following keypoint detectors in file matching2D.cpp and enable string-based selection based on detectorType
        //// -> HARRIS, FAST, BRISK, ORB, AKAZE, SIFT

        KeypointDetector keypointDetectorType = KeypointDetector::Shi_Tomasi;

        switch (keypointDetectorType)
        {
            case KeypointDetector::Shi_Tomasi:
                cout << "*** Using Shi-Tomasi keypoint detector" << endl;
                detKeypointsShiTomasi(keypoints, imgGray, false);
                break;
            case KeypointDetector::HARRIS:
                cout << "*** Using HARRIS keypoint detector" << endl;
                detKeypointsHarris(keypoints, imgGray, false);
                break;
            case KeypointDetector::FAST:
                cout << "*** Using FAST keypoint detector" << endl;
                detKeypointsFAST(keypoints, imgGray, false);
                break;
            case KeypointDetector::BRISK:
                cout << "*** Using BRISK keypoint detector" << endl;
                detKeypointsBRISK(keypoints, imgGray, false);
                break;
            case KeypointDetector::ORB:
                cout << "*** Using ORB keypoint detector" << endl;
                detKeypointsORB(keypoints, imgGray, false);
                break;
            case KeypointDetector::AKAZE:
                cout << "*** Using AKAZE keypoint detector" << endl;
                detKeypointsAKAZE(keypoints, imgGray, false);
                break;
            case KeypointDetector::SIFT:
                cout << "*** Using SIFT keypoint detector" << endl;
                detKeypointsSIFT(keypoints, imgGray, false);
                break;
            default:
                cout << "*** Not using a specified keypoint detector" << endl;
        }

        //// EOF STUDENT ASSIGNMENT

        //// STUDENT ASSIGNMENT
        //// TASK MP.3 -> only keep keypoints on the preceding vehicle
        /// (Remember, there are keypoints everywhere, e.g., on the road, on other vehicles, on the bridge, etc.
        /// We just want to keep the keypoints on the preceding vehicle)

        // only keep keypoints on the preceding vehicle
        bool bFocusOnVehicle = true;
        // define a rectangle that encloses the preceding vehicle
        cv::Rect vehicleRect(535, 180, 180, 150);
        if (bFocusOnVehicle)
        {
            for(auto it = keypoints.begin(); it != keypoints.end();)
            {
                // remove the keypoint if it is not contained within the rectangle of interest
                if(!vehicleRect.contains(it->pt))
                {
                    //cout << "||| Removing keypoint " << it->pt << " not contained in rectangle of interest" << endl;
                    keypoints.erase(it);
                }
                else
                {
                    //cout << "/// Keeping keypoint " << it->pt << " contained in rectangle of interest" << endl;
                    it++;
                }
            }
        }

        //// EOF STUDENT ASSIGNMENT

        // optional : limit number of keypoints (helpful for debugging and learning)
        // It helps to limit the number of keypoints if we have so many that the result is just a blur of colors
        bool bLimitKpts = false;
        if (bLimitKpts)
        {
            int maxKeypoints = 50;

            if (keypointDetectorType != KeypointDetector::Shi_Tomasi)
            { // there is no response info, so keep the first 50 as they are sorted in descending quality order
                keypoints.erase(keypoints.begin() + maxKeypoints, keypoints.end());
            }
            cv::KeyPointsFilter::retainBest(keypoints, maxKeypoints);
            cout << " NOTE: Keypoints have been limited!" << endl;
        }

        // push keypoints and descriptor for current frame to end of data buffer
        (dataBuffer.end() - 1)->keypoints = keypoints;
        cout << "#2 : DETECT KEYPOINTS done" << endl;

        /* EXTRACT KEYPOINT DESCRIPTORS */

        //// STUDENT ASSIGNMENT
        //// TASK MP.4 -> add the following descriptors in file matching2D.cpp and enable string-based selection based on descriptorType
        //// -> BRIEF, ORB, FREAK, AKAZE, SIFT

        cv::Mat descriptors;
        string descriptorType = "BRISK"; // BRISK, BRIEF, ORB, FREAK, AKAZE, SIFT
        descKeypoints((dataBuffer.end() - 1)->keypoints,
                      (dataBuffer.end() - 1)->cameraImg,
                      descriptors,
                      descriptorType);
        //// EOF STUDENT ASSIGNMENT

        // push descriptors for current frame to end of data buffer
        (dataBuffer.end() - 1)->descriptors = descriptors;

        cout << "#3 : EXTRACT DESCRIPTORS done" << endl;

        // wait until at least two images have been processed (we want to match keypoints between 2 images,
        // so if we have only one image then this won't work)
        if (dataBuffer.size() > 1)
        {

            /* MATCH KEYPOINT DESCRIPTORS */

            vector<cv::DMatch> matches;
            string matcherType = "MAT_BF";        // MAT_BF, MAT_FLANN
            string descriptorType = "DES_BINARY"; // DES_BINARY, DES_HOG
            string selectorType = "SEL_NN";       // SEL_NN, SEL_KNN

            //// STUDENT ASSIGNMENT
            //// TASK MP.5 -> add FLANN matching in file matching2D.cpp
            //// TASK MP.6 -> add KNN match selection and perform descriptor distance ratio filtering with t=0.8 in file matching2D.cpp

            try
            {
                matchDescriptors((dataBuffer.end() - 2)->keypoints, (dataBuffer.end() - 1)->keypoints,
                                 (dataBuffer.end() - 2)->descriptors, (dataBuffer.end() - 1)->descriptors,
                                 matches,
                                 descriptorType,
                                 matcherType,
                                 selectorType);
            }
            catch (const std::exception &ex)
            {
                std::cerr << "Exception: " << ex.what() << std::endl;
            }

            //// EOF STUDENT ASSIGNMENT

            // store matches in current data frame
            (dataBuffer.end() - 1)->keypointMatches = matches;

            cout << "#4 : MATCH KEYPOINT DESCRIPTORS done" << endl;

            // visualize matches between current and previous image
            bVis = false;
            if (bVis)
            {
                cv::Mat matchImg = ((dataBuffer.end() - 1)->cameraImg).clone();
                cv::drawMatches((dataBuffer.end() - 2)->cameraImg, (dataBuffer.end() - 2)->keypoints,
                                (dataBuffer.end() - 1)->cameraImg, (dataBuffer.end() - 1)->keypoints,
                                matches, matchImg,
                                cv::Scalar::all(-1), cv::Scalar::all(-1),
                                vector<char>(), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

                string windowName = "Matching keypoints between two camera images";
                cv::namedWindow(windowName, 7);
                cv::imshow(windowName, matchImg);
                cout << "Press key to continue to next image" << endl;
                cv::waitKey(0); // wait for key to be pressed
            }
            bVis = false;
        }

    } // eof loop over all images

    return 0;
}
