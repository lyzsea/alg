//
// Created by yz L on 2019-05-10.
//

#ifndef ALG_CHARMINDISTINCE_H
#define ALG_CHARMINDISTINCE_H

#include <vector>
#include <string>
#include <algorithm>

#include "palindrome.h"
#include "longDiffString.h"
/**
 *
 * @param src
 * @param target
 * @return
 */
std::vector<int> getCharMinDistanceBinarySearch(const std::string& src, const char target);

/**
 *
 * @param src
 * @param target
 * @return
 */
std::vector<int> getCharMinDistanceNormal(const std::string& src, char target);

/**
 *
 * @param perpageCount
 * @param src
 * @return
 */
std::vector<std::string> paginate(int perpageCount,const std::vector<std::string>& src);


/**
 *
 * @param nums1
 * @param nums2
 * @return
 */
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2);

/**
 *
 * @param nums
 * @param target
 * @return
 */
std::vector<int> twoSum(std::vector<int>& nums, int target);

#endif //ALG_CHARMINDISTINCE_H
