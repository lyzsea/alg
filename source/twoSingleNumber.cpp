//
// Created by yz L on 2019-10-21.
//
#include "../header/twoSingleNumber.h"

int CTwoSingleNumbers::findFirstOneIndex(int num) {
    int indexFirstOne =0;
    while (((num & 1) == 0) && (indexFirstOne < 32)) {
        num = num >> 1;
        ++indexFirstOne;
    }

    return indexFirstOne;
}

bool CTwoSingleNumbers::isBitOne(int num,int indexForOne) {
    return (num >> indexForOne)&1;
}

std::vector<int> CTwoSingleNumbers::singleNumber(std::vector<int>& nums) {
    int xorResult = 0;
    for (int i = 0; i < nums.size(); ++i) {
        xorResult ^= nums[i];
    }

    int indexFirstOne = findFirstOneIndex(xorResult);

    int firstOnceNum = 0;
    int secondOnceNum =0;
    for (int j = 0; j < nums.size(); ++j) {
        if (isBitOne(nums[j],indexFirstOne)) {
            firstOnceNum ^= nums[j];
        } else {
            secondOnceNum ^= nums[j];
        }
    }

    std::vector<int> result;
    result.push_back(firstOnceNum);
    result.push_back(secondOnceNum);

    return result;
}

