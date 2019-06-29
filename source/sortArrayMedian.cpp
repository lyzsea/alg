//
// Created by yz L on 2019-03-20.
//

#include "../header/sortAarrayMedian.h"

/**
 *
 * @param nums1
 * @param nums2
 * @return
 */
double CMedianSortArray::findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    int totalSize = nums1.size() + nums2.size();
    int mid = (totalSize + 1) / 2;

    int firIndex = 0, secIndex = 0;
    for (int i = 1; i < mid; ++i) {
        if (firIndex >= nums1.size()) {
            secIndex++;
        } else if (secIndex >= nums2.size()) {
            firIndex++;
        } else {
            (nums1[firIndex] < nums2[secIndex]) ? firIndex++ : secIndex++;
        }
    }

    if (firIndex == nums1.size()) {
        return totalSize % 2 == 0 ? (nums2[secIndex] + nums2[secIndex + 1]) / 2.0 : nums2[secIndex] / 1.0;
    }

    if (secIndex == nums2.size()) {
        return totalSize % 2 == 0 ? (nums1[firIndex] + nums1[firIndex + 1]) / 2.0 : nums1[firIndex] / 1.0;
    }

    // firIndex < nums1.size() && secIndex < nums2.size()
    if (totalSize % 2 == 1) {
        // odd number
        return (nums1[firIndex] < nums2[secIndex] ? nums1[firIndex] : nums2[secIndex]) / 1.0;
    }

    // even number
    int midFirst = nums1[firIndex];
    int midSecond = nums2[secIndex];
    // [1,2], [-1,3]情况处理
    if (midFirst < midSecond) {
        if (firIndex + 1 < nums1.size()) {
            midSecond = nums1[firIndex + 1] < nums2[secIndex] ? nums1[firIndex + 1] : nums2[secIndex];
        }
    } else {
        if (secIndex + 1 < nums2.size()) {
            midFirst = nums2[secIndex + 1] < nums1[firIndex] ? nums2[secIndex + 1] : nums1[firIndex];
        }
    }
    return (midFirst + midSecond) / 2.0;
}

