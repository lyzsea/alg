//
// Created by yz L on 2019-05-10.
//
#include <algorithm>
#include <string>
#include "commonHeaders.h"

/***
 * 给定一个字符串str以及一个指定字符char(该字符存在与str中)，返回一个整型数组表示str中每个字符到字符char的最短距离。
 * 如：（"aba",'a'）,返回 [0,1,0]
 */


int getMInDistance(int curIndex, const std::vector<int> &targetIndexVec);

std::vector<int> getCharMinDistance(const std::string& src, char target) {
    size_t srcLength = src.length();
    std::vector<int> targetIndexVec;
    for (int i = 0; i < srcLength; ++i) {
        if (src.at(i) == target) {
            targetIndexVec.emplace_back(i);
        }
    }

    std::vector<int> result(srcLength);
    for (int j = 0; j < srcLength; ++j) {
        if (src.at(j) == target) {
            result[j] = 0;
            continue;
        }

        result[j] = getMInDistance(j,targetIndexVec);
    }

    return result;
}

int getMInDistance(int curIndex, const std::vector<int> &targetIndexVec) {
    int beginIndex = *targetIndexVec.begin();
    if (curIndex < beginIndex) {
        return beginIndex - curIndex;
    }

    int backIndex = targetIndexVec.back();
    if (curIndex > backIndex) {
        return curIndex - backIndex;
    }

    int begin = 0;
    int end = targetIndexVec.size() -1;
    int mid = targetIndexVec.size()/2;

    while (mid > begin && mid < end) {
        if (curIndex < targetIndexVec[mid]) {
            end = mid;
            mid = (end + begin)/2;
        } else {
            begin = mid;
            mid = (end + begin)/2;
        }
    }

    int minDistance = std::min(curIndex - targetIndexVec[begin], targetIndexVec[end] - curIndex);

    return minDistance;
}