# Performance Evaluation

Ran a total of 42 experiments for 7 detectors and 6 descriptors

##Performance Evaluation 1: Number of Keypoints


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

##Performance Evaluation 3: Keypoint Detection and Descriptor Extraction

Log the time it takes for keypoint detection and descriptor extraction.



### Keypoint Detection Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 118.765 | 98.8713 | 94.21 | 88.6807 | 89.6244 | 105.308
HARRIS | 120.402 | 120.6 | 118.074 | 121.616 | 122.551 | 123.565
FAST | 2.71431 | 2.75979 | 2.75589 | 2.72761 | 2.74405 | 2.72712
SIFT | 245.113 | 252.642 | 257.995 | 261.054 | 276.946 | 312.633
AKAZE | 177.104 | 185.356 | 176.312 | 190.77 | 188.345 | 180.599
ORB | 16.6953 | 12.1151 | 10.2448 | 12.1241 | 16.7203 | 12.4686
BRISK | 49.3941 | 53.0137 | 49.6089 | 51.4609 | 56.611 | 49.7014


### Descriptor Extraction Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 14.9807 | 9.37991 | 19.545 | 163.441 | 434.393 | 123.073
HARRIS | 10.4121 | 7.771 | 20.109 | 158.665 | 427.609 | 123.689
FAST | 7.69915 | 3.41456 | 8.69911 | 80.2759 | 214.185 | 59.4854
SIFT | 6.64775 | 5.97948 | 1236.62 | 55.4768 | 222.988 | 256.996
AKAZE | 8.72879 | 6.95137 | 15.3676 | 47.0016 | 170.809 | 73.5159
ORB | 4.66649 | 2.23304 | 14.8244 | 33.7542 | 142.707 | 85.6144
BRISK | 4.53687 | 1.46616 | 11.5872 | 29.2931 | 113.753 | 33.114
