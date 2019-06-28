//
// Created by yz L on 2019-03-16.
//

#include <algorithm>
#include <unordered_map>

#include "../header/twoSumToTarget.h"
/**
 * return indices of the two numbers such that they add up to a specific target
 * @param nums
 * @param target
 * @return
 */
std::vector<int> CTwoSumToTarget::twoSumToTarget(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> maps;
    for (int i = 0; i < nums.size(); ++i) {
        if (maps.count(target - nums[i])) {
            return {maps[target - nums[i]], i};
        }
        maps[nums[i]] = i;
    }

    return {};
}

