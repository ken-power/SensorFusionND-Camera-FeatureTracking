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

### Total number of matched keypoints over 10 images
Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 767 | 944 | 1814 | 766 | 0 | 926
HARRIS | 142 | 173 | 320 | 146 | 0 | 163
FAST | 899 | 1099 | 2162 | 881 | 0 | 1048
SIFT | 304 | 338 | 0 | 274 | 0 | 801
AKAZE | 1215 | 1266 | 2372 | 1188 | 2518 | 1273
ORB | 751 | 545 | 1522 | 421 | 0 | 765
BRISK | 1570 | 1704 | 3020 | 1526 | 0 | 1662

### Average number of matched keypoints per image pair
Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 76 | 94 | 181 | 76 | 0 | 92
HARRIS | 14 | 17 | 32 | 14 | 0 | 16
FAST | 89 | 109 | 216 | 88 | 0 | 104
SIFT | 30 | 33 | 0 | 27 | 0 | 80
AKAZE | 121 | 126 | 237 | 118 | 251 | 127
ORB | 75 | 54 | 152 | 42 | 0 | 76
BRISK | 157 | 170 | 302 | 152 | 0 | 166

## Performance Evaluation 3: Keypoint Detection and Descriptor Extraction

Log the time it takes for keypoint detection and descriptor extraction.

### Keypoint Detection Times (milliseconds)

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 120.894 | 98.6991 | 189.334 | 94.3128 | 0 | 95.638
HARRIS | 114.667 | 118.014 | 242.595 | 117.921 | 0 | 112.599
FAST | 3.01243 | 2.70519 | 5.42207 | 2.71753 | 0 | 2.70133
SIFT | 276.294 | 265.98 | 0 | 272.924 | 0 | 258.66
AKAZE | 194.43 | 193.4 | 392.382 | 194.539 | 373.753 | 200.481
ORB | 17.6156 | 11.7999 | 18.8314 | 9.37503 | 0 | 10.4087
BRISK | 49.9805 | 51.558 | 97.2081 | 48.5545 | 0 | 48.6806


### Descriptor Extraction Times (milliseconds)

Detector - Descriptor|BRISK|BRIEF|ORB|FREAK|AKAZE|SIFT
 :--- | ---: | ---: | ---: | ---: | ---: | ---:
Shi-Tomasi | 17.2688 | 7.82821 | 38.1861 | 164.154 | 0 | 111.244
HARRIS | 10.1788 | 8.24074 | 39.3259 | 157.202 | 0 | 101.229
FAST | 7.83818 | 3.49795 | 17.6274 | 80.4039 | 0 | 55.2838
SIFT | 7.34987 | 4.814 | 0 | 60.3379 | 0 | 231.113
AKAZE | 11.1026 | 5.9066 | 38.9732 | 43.0918 | 350.274 | 74.3619
ORB | 6.93629 | 2.50195 | 34.1095 | 33.7581 | 0 | 67.9904
BRISK | 4.40716 | 1.38797 | 20.4963 | 27.8051 | 0 | 41.4236
