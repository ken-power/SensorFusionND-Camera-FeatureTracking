# Performance Evaluation
These results are recorded from running a total of 35 experiments based on combinations of 7 detectors and 6 descriptors.

## Performance Evaluation 1: Number of Keypoints


Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.

Detector | Keypoints
 :--- | ---:
Shi-Tomasi | 13423
HARRIS | 1737
FAST | 17874
BRISK | 27116
ORB | 5000
AKAZE | 13430
SIFT | 13861

## Performance Evaluation 2: Number of Matched Keypoints

Count the number of matched keypoints for all 10 images using all possible combinations of detectors and descriptors. In the matching step, the BF approach is used with the descriptor distance ratio set to 0.8.

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 767 | 944 | 1814 | 766 | 0 | 926
HARRIS | 142 | 173 | 320 | 146 | 0 | 163
FAST | 899 | 1099 | 2162 | 881 | 0 | 1048
SIFT | 304 | 338 | 0 | 274 | 0 | 801
AKAZE | 1215 | 1266 | 2372 | 1188 | 2518 | 1273
ORB | 751 | 545 | 1522 | 421 | 0 | 765
BRISK | 1570 | 1704 | 3020 | 1526 | 0 | 1662

## Performance Evaluation 3: Keypoint Detection and Descriptor Extraction

Log the time it takes for keypoint detection and descriptor extraction.



### Keypoint Detection Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 113.961 | 103.281 | 182.746 | 88.6761 | 0 | 88.6581
HARRIS | 117.739 | 115.977 | 224.026 | 114.519 | 0 | 120.658
FAST | 2.75996 | 2.84834 | 5.50425 | 2.74408 | 0 | 2.74581
SIFT | 251.051 | 247.2 | 0 | 244.247 | 0 | 260.259
AKAZE | 170.732 | 174.562 | 340.939 | 175.438 | 368.825 | 183.47
ORB | 17.722 | 13.3629 | 20.6844 | 11.4591 | 0 | 12.4044
BRISK | 49.2949 | 49.3449 | 103.928 | 51.1041 | 0 | 49.9847


### Descriptor Extraction Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 16.0448 | 8.91525 | 40.1351 | 164.883 | 0 | 108.667
HARRIS | 9.76207 | 5.42603 | 41.2102 | 155.613 | 0 | 123.167
FAST | 8.54358 | 3.68155 | 18.1524 | 80.7901 | 0 | 57.0617
SIFT | 6.2278 | 5.26704 | 0 | 55.5796 | 0 | 197.059
AKAZE | 8.55506 | 4.42716 | 32.1053 | 43.9621 | 311.096 | 67.973
ORB | 3.00601 | 2.8468 | 25.0946 | 31.4454 | 0 | 59.4137
BRISK | 4.30439 | 2.03225 | 21.3602 | 27.7593 | 0 | 31.6481
