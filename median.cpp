//
// Created by yz L on 2019-03-20.
//

#include "median.h"

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {

    int totalSize = nums1.size() + nums2.size();
    int mid = (totalSize+1) / 2;


    int mIndex = 0, nIndex = 0;
    for (int i = 1; i < mid; ++i) {
        if (mIndex < nums1.size() && nIndex < nums2.size()) {
            if (nums1[mIndex] < nums2[nIndex]) {
                mIndex++;
            } else {
                nIndex++;
            }
        } else if (mIndex >= nums1.size()) {
            nIndex++;
        } else if (nIndex >= nums2.size()) {
            mIndex++;
        }
    }

    if (mIndex < nums1.size() && nIndex < nums2.size()) {
        if (totalSize % 2 == 0) {
            if (nums1[mIndex] < nums2[nIndex]) {
                int midFirst = nums1[mIndex];
                int midSecond = nums2[nIndex];
                if (mIndex + 1 < nums1.size()) {
                    midSecond = nums1[mIndex + 1] < nums2[nIndex] ? nums1[mIndex + 1] : nums2[nIndex];
                }
                return (midFirst + midSecond) / 2.0;
            } else {
                int midFirst = nums2[nIndex];
                int midSecond = nums1[mIndex];
                if (nIndex + 1 < nums2.size()) {
                    midSecond = nums2[nIndex + 1] < nums1[mIndex] ? nums2[nIndex + 1] : nums1[mIndex];
                }
                return (midFirst + midSecond) / 2.0;
            }
        } else {
            return (nums1[mIndex] < nums2[nIndex] ? nums1[mIndex] : nums2[nIndex]) / 1.0;
        }
    } else if (mIndex == nums1.size()) {
        return totalSize % 2 == 0 ? (nums2[nIndex] + nums2[nIndex + 1]) / 2.0 : nums2[nIndex] / 1.0;
    } else {
        return totalSize % 2 == 0 ? (nums1[mIndex] + nums1[mIndex + 1]) / 2.0 : nums1[mIndex] / 1.0;
    }

}

