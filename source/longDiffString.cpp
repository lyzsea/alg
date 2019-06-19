//
// Created by yz L on 2019-03-21.
//
#include "../header/longDiffString.h"
#include "../header/functionTimer.h"
#include <unordered_set>
#include <vector>
#include <algorithm>


std::string CLongDiffString::longestDiffSubstring(const std::string& src,ALG_TYPE alg_type) {

    switch (alg_type) {
        case ALG_TYPE::COMMON :
            return commonTraverse(src);
        case ALG_TYPE::HASH :
            return asciiCodeHash(src);
        default:

            break;
    }
}

/**
 * 常规算法实现,时间复杂度: O(256N)
 * @param src
 * @return 最大非重复子串
 */
std::string CLongDiffString::commonTraverse(const std::string& src) {
    CFunctionTimer timer(__FUNCTION__);
    int maxLength = 0;// 最大非重复子串长度
    int indexForMaxDiffStr = 0;

    int length = 0;//临时变量，记录当前字符开始的最大非重复子串长度
    std::unordered_set<int> traversedHash;
    for (int i = 0; i < src.length() && src.length() - i > maxLength; ++i) {
        for (int j = i; j < src.length(); ++j) {
            if (traversedHash.count(src[j])) {
                break;
            } else {
                ++length;
                traversedHash.insert(src[j]);
            }
        }

        if (length > maxLength) {
            maxLength = length;
            indexForMaxDiffStr = i;
        }
        length = 0;
        traversedHash.clear();
    }
    // 最大非重复子串长度
    maxLength = maxLength > length ? maxLength : length;

    return src.substr(indexForMaxDiffStr, maxLength);
}

/**
 * 利用assic码值有限区间，用ascii code值作为hash数组索引，省去对已遍历非重复字符的再次遍历
 * 时间复杂度: O(N)
 * @param src
 * @return
 */
std::string CLongDiffString::asciiCodeHash(const std::string& src) {
    CFunctionTimer timer(__FUNCTION__);
    const int srcLength = src.length();

    std::vector<int> pos(256, -1);
    int basePos = 0;
    int maxLength = -1;
    for (int i = 0; i < srcLength; i++) {
        // 起始位置前移以后，之前出现过的字符的索引值要更新为当前的
        if (pos[src[i]] < basePos) {
            pos[src[i]] = i;
        } else {
            maxLength = std::max(i - basePos, maxLength);

            // 起始位置前移
            basePos = pos[src[i]] + 1;
            pos[src[i]] = i;
        }
    }

    maxLength = std::max(srcLength - basePos, maxLength);

    return src.substr(basePos,maxLength);
}

