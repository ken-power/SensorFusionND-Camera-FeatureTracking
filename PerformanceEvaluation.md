# Performance Evaluation
These results are recorded from running a total of 35 experiments based on combinations of 7 detectors and 6 descriptors.

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
Shi-Tomasi | 120.312 | 88.3276 | 183.283 | 89.9165 | 0 | 92.0328
HARRIS | 114.282 | 115.166 | 232.401 | 115.835 | 0 | 122.046
FAST | 2.76322 | 2.78845 | 5.4921 | 2.75225 | 0 | 2.73192
SIFT | 252.117 | 244.78 | 0 | 254.475 | 0 | 246.391
AKAZE | 175.605 | 182.519 | 348.497 | 175.502 | 344.059 | 171.631
ORB | 17.1022 | 12.6855 | 22.2721 | 10.1853 | 0 | 9.35287
BRISK | 49.6706 | 48.6664 | 100.244 | 48.5396 | 0 | 48.492


### Descriptor Extraction Times

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 15.7014 | 7.7325 | 40.1788 | 165.593 | 0 | 108.507
HARRIS | 7.96803 | 8.90339 | 35.8579 | 159.361 | 0 | 115.151
FAST | 8.29369 | 3.7715 | 17.3768 | 80.0531 | 0 | 53.8869
SIFT | 10.1943 | 5.15596 | 0 | 56.9944 | 0 | 202.481
AKAZE | 6.03055 | 4.84432 | 38.1401 | 46.952 | 315.446 | 65.7151
ORB | 4.77365 | 3.72201 | 31.8176 | 32.3734 | 0 | 62.0946
BRISK | 4.37057 | 1.38459 | 22.7182 | 28.3053 | 0 | 33.9675
