# Performance Evaluation
These results are recorded from running a total of 42 experiments: one for each combination of 7 detectors and 6 descriptors.

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
AKAZE | 1215 | 1266 | 1186 | 1188 | 1259 | 1273
ORB | 751 | 545 | 761 | 421 | 0 | 765
BRISK | 1570 | 1704 | 1510 | 1526 | 0 | 1662

## Performance Evaluation 3: Keypoint Detection and Descriptor Extraction

Log the time it takes for keypoint detection and descriptor extraction.



### Keypoint Detection Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 107.485 | 105.129 | 93.6155 | 86.5034 | 89.612 | 94.5035
HARRIS | 119.125 | 116.159 | 117.335 | 116.321 | 119.982 | 122.914
FAST | 2.73698 | 2.78225 | 2.77025 | 2.74277 | 2.75944 | 2.81364
SIFT | 263.997 | 265.838 | 256.264 | 261.532 | 270.867 | 248.117
AKAZE | 169.812 | 172.751 | 180.856 | 180.175 | 181.295 | 193.112
ORB | 14.9903 | 10.4194 | 10.2988 | 10.2727 | 11.756 | 11.138
BRISK | 48.9156 | 49.7442 | 48.2261 | 50.3831 | 53.3521 | 48.9566


### Descriptor Extraction Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 16.0932 | 9.62419 | 21.5167 | 164.073 | 418.224 | 122.033
HARRIS | 9.23749 | 7.43016 | 19.0381 | 157.332 | 455.653 | 123.45
FAST | 7.87832 | 3.62289 | 8.96998 | 80.6087 | 214.836 | 63.8117
SIFT | 7.32391 | 3.34551 | 1193.94 | 59.7881 | 217.326 | 196.038
AKAZE | 12.2308 | 8.36895 | 16.9348 | 43.8659 | 169.224 | 73.0567
ORB | 3.8209 | 2.28283 | 12.3906 | 33.3751 | 143.817 | 68.0709
BRISK | 4.25674 | 1.37902 | 11.6803 | 28.5187 | 116.883 | 31.2402
