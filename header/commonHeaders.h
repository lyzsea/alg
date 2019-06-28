//
// Created by yz L on 2019-05-10.
//

#ifndef ALG_CHARMINDISTINCE_H
#define ALG_CHARMINDISTINCE_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "palindrome.h"
#include "longDiffString.h"
#include "longCommString.h"
#include "minDistanceToChar.h"
#include "zigzagConversion.h"
#include "twoSumToTarget.h"

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

#endif //ALG_CHARMINDISTINCE_H
