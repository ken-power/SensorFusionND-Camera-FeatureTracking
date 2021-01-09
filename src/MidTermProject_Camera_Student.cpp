/* INCLUDES FOR THIS PROJECT */
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>

#include <boost/circular_buffer.hpp>

#include "dataStructures.h"
#include "matching2D.hpp"
#include "reporting.h"

using namespace std;


void RunExperiment(Experiment &experiment);
void RunExperimentSet(Hyperparameters hyperparameters, const std::vector<KeypointDetector> detectors, const std::vector<string> descriptors);

/* MAIN PROGRAM */
int main(int argc, const char *argv[])
{
    Hyperparameters hyperparameters = Hyperparameters();

    std::vector<KeypointDetector> detectors = {
            KeypointDetector::Shi_Tomasi,
            KeypointDetector::HARRIS,
            KeypointDetector::FAST,
            KeypointDetector::SIFT,
            KeypointDetector::AKAZE,
            KeypointDetector::ORB,
            KeypointDetector::BRISK
    };

    std::vector<string> descriptors = {
            "BRISK",
            "BRIEF",
            "ORB",
            "FREAK",
            "AKAZE",
            "SIFT"
    };

    // Run experiments for all combinations of detectors and descriptors
    RunExperimentSet(hyperparameters, detectors, descriptors);

    return 0;
}

void RunExperimentSet(Hyperparameters hyperparameters, const std::vector<KeypointDetector> detectors, const std::vector<string> descriptors)
{
    TotalKeypoints keypoints;
    PerformanceEvaluationSummary performanceData = PerformanceEvaluationSummary();
    performanceData.keypoints = keypoints;

    std::vector<TotalKeypointMatches> keypointMatches;
    performanceData.keypointMatches = keypointMatches;

    std::vector<AverageProcessingTimes> processingTimes;
    performanceData.processingTimes = processingTimes;

    unsigned int experimentCount = 0;
    for(auto detector:detectors)
    {
        for(auto descriptor:descriptors)
        {
            cout << "\n*** RUNNING EXPERIMENT " << experimentCount << " WITH detector = " << DetectorNameAsString(detector) << "  and descriptor = " << descriptor << " ***" << endl;
            hyperparameters.keypointDetector = detector;
            hyperparameters.descriptor = descriptor;

            Experiment ex = Experiment();
            ex.hyperparameters = hyperparameters;

            // There are some combinations of detector and descriptor that do not work together:
            if(descriptor == "AKAZE")
            {
                // AKAZE descriptors work only with AKAZE detectors.
                if (detector == AKAZE)
                {
                    RunExperiment(ex);
                }
                else
                {
                    cerr << "Can't use AKAZE descriptor with non-AKAZE detector." << endl;
                    continue;
                }
            }

            if(descriptor == "ORB")
            {
                // ORB detectors do not work with SIFT descriptors.
                if (detector != SIFT)
                {
                    RunExperiment(ex);
                }
                else
                {
                    cerr << "Can't use ORB descriptor with SIFT detector." << endl;
                    continue;
                }
            }

            // All other detector-descriptor combinations are assumed to be valid
            RunExperiment(ex);

            ProcessExperimentResults(ex, performanceData, false);

            experimentCount++;
        }
    }

    cout << "# Performance Evaluation" << endl;
    cout << "These results are recorded from running a total of " << experimentCount << " experiments based on combinations of " << detectors.size() << " detectors and " << descriptors.size() << " descriptors." << endl;

    DisplayKeypointDetectionSummary(performanceData.keypoints);
    DisplayKeypointMatchingSummary(performanceData.keypointMatches);
    DisplayProcessingTimesSummary(performanceData.processingTimes);
}


/*
 * This function encapsulates running an experiment with a given combination of detector, descriptor, matcher,
 * descriptor type, and selector.
 */
void RunExperiment(Experiment &experiment)
{
    /* INIT VARIABLES AND DATA STRUCTURES */
    unsigned int firstImage = 0;
    unsigned int secondImage = 1;

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

    /* MAIN LOOP OVER ALL IMAGES */
    ExperimentResult experimentResult;
    const bool visualizeImages = experiment.hyperparameters.visualizeImageMatches;

    for (size_t imgIndex = 0; imgIndex <= imgEndIndex - imgStartIndex; imgIndex++)
    {
        experimentResult = ExperimentResult();
        /* LOAD IMAGE INTO BUFFER */

        // assemble filenames for current index
        ostringstream imgNumber;
        imgNumber << setfill('0') << setw(imgFillWidth) << imgStartIndex + imgIndex;
        string imgFullFilename = imgBasePath + imgPrefix + imgNumber.str() + imgFileType;

        // load image from file and convert to grayscale
        cv::Mat img, imgGray;
        img = cv::imread(imgFullFilename);
        cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

        experimentResult.keypointCount.imageName = imgFullFilename;

        //// STUDENT ASSIGNMENT
        //// TASK MP.1 -> replace the following code with ring buffer of size dataBufferSize

        // push image into data frame buffer
        DataFrame frame; // instantiate the dataframe
        frame.cameraImg = imgGray; // add the image to the dataframe
        dataBuffer.push_back(frame); // push the dataframe onto the data buffer

        //// EOF STUDENT ASSIGNMENT
        cout << "#1 : LOAD IMAGE INTO BUFFER done" << endl;

        /* DETECT IMAGE KEYPOINTS */

        // extract 2D keypoints from current image
        vector<cv::KeyPoint> keypoints; // create empty feature list for current image

        //// STUDENT ASSIGNMENT
        //// TASK MP.2 -> add the following keypoint detectors in file matching2D.cpp and enable string-based selection based on detectorType
        //// -> HARRIS, FAST, BRISK, ORB, AKAZE, SIFT

        switch (experiment.hyperparameters.keypointDetector)
        {
            case KeypointDetector::Shi_Tomasi:
                detKeypointsShiTomasi(keypoints, imgGray, visualizeImages, experimentResult);
                break;
            case KeypointDetector::HARRIS:
                detKeypointsHarris(keypoints, imgGray, visualizeImages, experimentResult);
                break;
            case KeypointDetector::FAST:
                detKeypointsFAST(keypoints, imgGray, visualizeImages, experimentResult);
                break;
            case KeypointDetector::BRISK:
                detKeypointsBRISK(keypoints, imgGray, visualizeImages, experimentResult);
                break;
            case KeypointDetector::ORB:
                detKeypointsORB(keypoints, imgGray, visualizeImages, experimentResult);
                break;
            case KeypointDetector::AKAZE:
                detKeypointsAKAZE(keypoints, imgGray, visualizeImages, experimentResult);
                break;
            case KeypointDetector::SIFT:
                detKeypointsSIFT(keypoints, imgGray, visualizeImages, experimentResult);
                break;
            default:
                cerr << "Attempting to use an unsupported keypoint detector" << endl;
        }

        //// EOF STUDENT ASSIGNMENT

        //// STUDENT ASSIGNMENT
        //// TASK MP.3 -> only keep keypoints on the preceding vehicle
        /// (Remember, there are keypoints everywhere, e.g., on the road, on other vehicles, on the bridge, etc.
        /// We just want to keep the keypoints on the preceding vehicle)

        // define a rectangle that encloses the preceding vehicle
        cv::Rect vehicleRect(535, 180, 180, 150);
        if (experiment.hyperparameters.isFocusOnPrecedingVehicleOnly)
        {
            cout << "Focusing just on the preceding vehicle " << endl;
            cout << "Total Keypoints detected in the image = " << keypoints.size() << endl;
            experimentResult.keypointCount.totalKeypoints = keypoints.size();

            for(auto it = keypoints.begin(); it != keypoints.end();)
            {
                // remove the keypoint if it is not contained within the rectangle of interest
                if(!vehicleRect.contains(it->pt))
                {
                    keypoints.erase(it);
                }
                else
                {
                    it++;
                }
            }
            experimentResult.keypointCount.precedingVehicleKeypoints = keypoints.size();
            double percentageKeypointsRemoved = 100 -
                                                (static_cast<double>(experimentResult.keypointCount.precedingVehicleKeypoints) /
                                                 static_cast<double>(experimentResult.keypointCount.totalKeypoints) *
                                                 100);
            cout << "Keypoints detected on the preceding vehicle = " << experimentResult.keypointCount.precedingVehicleKeypoints << "; hence " << percentageKeypointsRemoved
                 << "% of keypoints removed" << endl;
        }

        //// EOF STUDENT ASSIGNMENT

        // optional : limit number of keypoints (helpful for debugging and learning)
        // It helps to limit the number of keypoints if we have so many that the result is just a blur of colors
        bool bLimitKpts = false;
        if (bLimitKpts)
        {
            int maxKeypoints = 50;

            if (experiment.hyperparameters.keypointDetector != KeypointDetector::Shi_Tomasi)
            { // there is no response info, so keep the first 50 as they are sorted in descending quality order
                keypoints.erase(keypoints.begin() + maxKeypoints, keypoints.end());
            }
            cv::KeyPointsFilter::retainBest(keypoints, maxKeypoints);
        }

        // push keypoints and descriptor for current frame to end of data buffer
        (dataBuffer.end() - 1)->keypoints = keypoints;
        cout << "#2 : DETECT KEYPOINTS done" << endl;

        /* EXTRACT KEYPOINT DESCRIPTORS */

        //// STUDENT ASSIGNMENT
        //// TASK MP.4 -> add the following descriptors in file matching2D.cpp and enable string-based selection based on descriptorType
        //// -> BRIEF, ORB, FREAK, AKAZE, SIFT

        cv::Mat descriptors;
        descKeypoints((dataBuffer.end() - 1)->keypoints,
                      (dataBuffer.end() - 1)->cameraImg,
                      descriptors,
                      experiment.hyperparameters.descriptor,
                      experimentResult);
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
            //// STUDENT ASSIGNMENT
            //// TASK MP.5 -> add FLANN matching in file matching2D.cpp
            //// TASK MP.6 -> add KNN match selection and perform descriptor distance ratio filtering with t=0.8 in file matching2D.cpp

            try
            {
                experimentResult.keypointMatch.matchedImagePair.first = firstImage;
                experimentResult.keypointMatch.matchedImagePair.second = secondImage;

                if(experiment.hyperparameters.keypointDetector == SIFT || experiment.hyperparameters.descriptor == "SIFT")
                {
                    experiment.hyperparameters.matcherType = "MAT_FLANN";
                    experiment.hyperparameters.descriptorType = "DES_HOG";
                }
                else
                {
                    experiment.hyperparameters.matcherType = "MAT_BF";
                    experiment.hyperparameters.descriptorType = "DES_BINARY";
                }

                matchDescriptors((dataBuffer.end() - 2)->keypoints, (dataBuffer.end() - 1)->keypoints,
                                 (dataBuffer.end() - 2)->descriptors, (dataBuffer.end() - 1)->descriptors,
                                 matches,
                                 experiment.hyperparameters.descriptorType,
                                 experiment.hyperparameters.matcherType,
                                 experiment.hyperparameters.selectorType,
                                 experimentResult);
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
            if (visualizeImages)
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

            firstImage++;
            secondImage++;
        }

        experiment.result.push_back(experimentResult);
    } // eof loop over all images

}
