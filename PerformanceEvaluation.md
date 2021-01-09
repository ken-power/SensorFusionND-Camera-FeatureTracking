# Performance Evaluation
These results are recorded from running a total of 35 experiments based on combinations of 7 detectors and 6 descriptors.

## Performance Evaluation 1: Number of Keypoints


Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.

Detector  | Total keypoints from all 10 images  | Total keypoints in scene (average per image) | Keypoints detected on preceding vehicle (average per image) | % keypoints removed from scene to focus on preceding vehicle
 :--- | ---: | ---: | ---: | ---: 
Shi-Tomasi | 13423 | 1342 | 117 | 91.2166
HARRIS | 1737 | 173 | 24 | 85.7225
FAST | 17874 | 1787 | 149 | 91.6583
BRISK | 27116 | 2711 | 276 | 89.8141
ORB | 5000 | 500 | 116 | 76.78
AKAZE | 13430 | 1343 | 167 | 87.5652
SIFT | 13861 | 1386 | 138 | 90.0007

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
Shi-Tomasi | 109.364 | 102.18 | 185.867 | 94.1761 | 0 | 88.345
HARRIS | 114.897 | 118.228 | 222.378 | 112.235 | 0 | 115.549
FAST | 2.7077 | 2.71652 | 5.54807 | 2.76621 | 0 | 2.75124
SIFT | 296.14 | 284.862 | 0 | 285.346 | 0 | 280.37
AKAZE | 207.72 | 182.869 | 394.39 | 193.163 | 397.368 | 208.516
ORB | 15.6676 | 10.7483 | 21.9879 | 12.1309 | 0 | 12.7008
BRISK | 49.3173 | 50.2333 | 99.3602 | 49.592 | 0 | 49.2176


### Descriptor Extraction Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 18.8685 | 8.25273 | 41.7754 | 164.022 | 0 | 107.545
HARRIS | 8.74428 | 6.85154 | 39.6794 | 155.657 | 0 | 105.817
FAST | 7.6614 | 3.4313 | 17.0852 | 85.5186 | 0 | 53.9945
SIFT | 8.9777 | 6.99016 | 0 | 54.0525 | 0 | 203.999
AKAZE | 9.09969 | 8.53179 | 41.2887 | 50.1621 | 358.618 | 84.7348
ORB | 3.99467 | 6.36938 | 28.2767 | 35.8993 | 0 | 72.1317
BRISK | 4.48616 | 1.36667 | 24.6825 | 28.21 | 0 | 31.7754
