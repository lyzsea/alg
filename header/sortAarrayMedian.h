//
// Created by yz L on 2019-06-29.
//
/**
 * 4.There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

https://leetcode-cn.com/problems/median-of-two-sorted-arrays
*/
#ifndef ALG_SORTAARRAYMEDIAN_H
#define ALG_SORTAARRAYMEDIAN_H

#include <vector>

#include "singleton.h"

class CMedianSortArray {
    friend class CSingleton<CMedianSortArray>;

public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
};
#endif //ALG_SORTAARRAYMEDIAN_H
