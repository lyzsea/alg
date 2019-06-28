//
// Created by yz L on 2019-06-28.
//
/**
 * 1. Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

https://leetcode-cn.com/problems/two-sum
*/
#ifndef ALG_CTWOSUMTOTARGET_H
#define ALG_CTWOSUMTOTARGET_H

#include <vector>
#include "singleton.h"

class CTwoSumToTarget {
    friend class CSingleton<CTwoSumToTarget>;

public:
    std::vector<int> twoSumToTarget(std::vector<int>& nums, int target);
};
#endif //ALG_CTWOSUMTOTARGET_H
