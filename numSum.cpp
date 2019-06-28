//
// Created by yz L on 2019-03-16.
//

#include <algorithm>
#include <unordered_map>

#include "header/commonHeaders.h"

/**
 * 1. Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

https://leetcode-cn.com/problems/two-sum
*/


/**
 *
 * @param nums
 * @param target
 * @return
 */
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int,int> maps;
    for (int i = 0; i < nums.size(); ++i) {
        if (maps.count(target - nums[i])) {
            return {maps[target - nums[i]],i};
        }
        maps[nums[i]]=i;
    }

    return {};
}

