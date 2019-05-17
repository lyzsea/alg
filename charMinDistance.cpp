//
// Created by yz L on 2019-05-10.
//
#include "commonHeaders.h"
#include "functionTimer.h"

/*** 题目描述
 * 给定一个字符串String以及一个字符Char，请编程返回一个数组来表达String中各字符到字符Char的最短距离。
 * 例如:
 * 输入: String = "lovewejoydata", Char = 'e'
 * 输出: [3, 2, 1, 0, 1, 0, 1, 2, 3, 4, 5, 6，7]
 */

/**
 * 二分查找实现
 * @param curIndex
 * @param targetIndexVec
 * @return
 */
int getMinDistanceBinarySearch(int curIndex, const std::vector<int> &targetIndexVec);

/**
 * 正常思路，顺序遍历查找
 * @param curIndex
 * @param startItor
 * @param targetIndexVec
 * @return
 */
int getMinDistanceNormal(int curIndex,
                   std::vector<int>::const_iterator startItor,
                   const std::vector<int> &targetIndexVec);

/**
 * 子数组利用二分查找实现,更高效
 * @param src
 * @param target
 * @return
 */
std::vector<int> getCharMinDistanceBinarySearch(const std::string& src, char target) {
    CFunctionTimer timer(__FUNCTION__);
    size_t srcLength = src.length();
    std::vector<int> targetIndexVec;
    for (int i = 0; i < srcLength; ++i) {
        if (src.at(i) == target) {
            targetIndexVec.emplace_back(i);
        }
    }
    assert(!targetIndexVec.empty());

    std::vector<int> result(srcLength);
    for (int j = 0; j < srcLength; ++j) {
        if (src.at(j) == target) {
            result[j] = 0;
            continue;
        }

        result[j] = getMinDistanceBinarySearch(j,targetIndexVec);
    }

    return result;
}

/**
 * 正常思路，顺序遍历查找
 * @param src
 * @param target
 * @return
 */
std::vector<int> getCharMinDistanceNormal(const std::string& src, char target) {
    CFunctionTimer timer(__FUNCTION__);
    size_t srcLength = src.length();
    std::vector<int> targetIndexVec;
    for (int i = 0; i < srcLength; ++i) {
        if (src.at(i) == target) {
            targetIndexVec.emplace_back(i);
        }
    }
    assert(!targetIndexVec.empty());

    std::vector<int>::const_iterator startItor = targetIndexVec.begin();

    std::vector<int> result(srcLength);
    for (int j = 0; j < srcLength; ++j) {
        if (src.at(j) == target) {
            result[j] = 0;
            continue;
        }
        result[j] = getMinDistanceNormal(j,startItor,targetIndexVec);
    }

    return result;
}

int getMinDistanceBinarySearch(int curIndex, const std::vector<int> &targetIndexVec) {
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

int getMinDistanceNormal(int curIndex,
                         std::vector<int>::const_iterator startItor,
                         const std::vector<int> &targetIndexVec) {
    int beginIndex = *targetIndexVec.begin();
    if (curIndex < beginIndex) {
        return beginIndex - curIndex;
    }

    int backIndex = targetIndexVec.back();
    if (curIndex > backIndex) {
        return curIndex - backIndex;
    }

    do {
        std::vector<int>::const_iterator preItor = startItor;
        startItor++;

        if (curIndex < *startItor) {
            return std::min(curIndex - *preItor, *startItor - curIndex);
        }

    } while (startItor != targetIndexVec.end());

    assert(false);
    return -1;
}