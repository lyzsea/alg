//
// Created by yz L on 2019-03-16.
//

#include <algorithm>
#include <unordered_map>

#include "commonHeaders.h"

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

