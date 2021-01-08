# Performance Evaluation
These results are recorded from running a total of 36 experiments based on combinations of 7 detectors and 6 descriptors.

## Performance Evaluation 1: Number of Keypoints


Count the number of keypoints on the preceding vehicle for all 10 images and take note of the distribution of their neighborhood size. Do this for all the detectors you have implemented.

Detector | Keypoints
 :--- | ---:
SHI_TOMASI | 13423
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
Shi-Tomasi | 767 | 944 | 907 | 766 | 0 | 926
HARRIS | 142 | 173 | 160 | 146 | 0 | 163
FAST | 899 | 1099 | 1081 | 881 | 0 | 1048
SIFT | 304 | 338 | 0 | 274 | 0 | 801
AKAZE | 1215 | 1266 | 1186 | 1188 | 2518 | 1273
ORB | 751 | 545 | 761 | 421 | 0 | 765
BRISK | 1570 | 1704 | 1510 | 1526 | 0 | 1662

## Performance Evaluation 3: Keypoint Detection and Descriptor Extraction

Log the time it takes for keypoint detection and descriptor extraction.



### Keypoint Detection Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 115.937 | 106.124 | 96.2781 | 93.8342 | 0 | 89.0843
HARRIS | 137.489 | 117.456 | 126.131 | 118.226 | 0 | 176.392
FAST | 3.75413 | 3.05952 | 2.80523 | 2.95257 | 0 | 3.04919
SIFT | 271.027 | 276.062 | 270.931 | 253.453 | 0 | 238.296
AKAZE | 162.557 | 164.013 | 166.528 | 166.955 | 358.845 | 178.23
ORB | 16.917 | 12.3794 | 10.242 | 9.58655 | 0 | 11.884
BRISK | 52.2162 | 52.499 | 51.9826 | 50.8715 | 0 | 49.5557


### Descriptor Extraction Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 17.9958 | 7.00061 | 18.4831 | 166.194 | 0 | 121.971
HARRIS | 8.75284 | 8.5545 | 22.1412 | 159.713 | 0 | 169.908
FAST | 11.1683 | 3.78494 | 8.84676 | 85.7475 | 0 | 64.7644
SIFT | 7.94469 | 5.2617 | 1350.53 | 59.9803 | 0 | 198.556
AKAZE | 8.21356 | 5.27437 | 20.9913 | 44.4833 | 316.359 | 64.9904
ORB | 4.25512 | 2.1176 | 15.4601 | 32.2332 | 0 | 59.6432
BRISK | 5.02928 | 1.45964 | 13.6441 | 28.4404 | 0 | 36.8251
