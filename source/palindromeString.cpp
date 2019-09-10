//
// Created by yz L on 2019-03-21.
//
/**
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：

输入: "cbbd"
输出: "bb"
*/


#include <iostream>
#include <vector>
#include "../header/palindromeString.h"

/**
 * find最长回文子串
 * @param src
 * @param algType
 * @return
 */
std::string CPalindrome::findLongestPalindrome(const std::string& src,ALG_TYPE algType) {
    switch (algType) {
        case ALG_TYPE::CENTRE_SPREAD :
            this->longestPalindromeStr = centreSpread(src);
            break;
        case ALG_TYPE::MANACHER :
            this->longestPalindromeStr = manacher(src);
            break;
        case REVERSE:
            this->longestPalindromeStr = reverseLongestSubString(src);
            break;
        default:
            this->longestPalindromeStr = manacher(src);
            break;
    }

    return this->longestPalindromeStr;
}

std::string CPalindrome::reverseLongestSubString(const std::string& src) {
    std::string reverseSrc = src;
    std::reverse(reverseSrc.begin(),reverseSrc.end());

    std::vector<std::vector<int>> matrix(src.size());
    for (int i = 0; i < src.size(); ++i) {
        matrix[i].resize(src.size(),0);
    }

    int maxCommLength = 0;
    int indexForMaxLength =0;
    for (int i = 0; i < src.size(); ++i) {
        for (int j = 0; j < src.size(); ++j) {
            if (src[i] != reverseSrc[j]) {
                continue;
            }

            matrix[i][j] = i > 0 && j > 0 ? matrix[i - 1][j - 1] + 1 : 1;

            if (matrix[i][j] > maxCommLength) {
                maxCommLength = matrix[i][j];
                indexForMaxLength = i;
            }
        }
    }

    return maxCommLength > 0 ? src.substr(indexForMaxLength - maxCommLength + 1, maxCommLength) : "";
}

/**
 * 马拉车算法，即每个字符中间插入特殊字符，使其变为奇数长度字符串
 * 如： abba  -> #a#b#b#a#
 * @param src
 * @return
 */
std::string CPalindrome::manacher(const std::string &src) {
    // 插入特殊字符
    std::string transform(src.size()*2+1,'#');
    for (int i = 0; i < transform.size(); ++i) {
        if (i%2 == 1) {
            transform[i] = src[(i+1)/2-1];
        }
    }

    std::cout<<"transform string: "<< transform<<std::endl;

    // transform中每个字符以其自身为中心的最长回文串的半径长度
    std::vector<int> palindromeLen(transform.size(), 0);
    int maxSubMiddle =0;//已遍历最长回文子串的中间字符索引
    int maxSubRight = 0;//已遍历最长回文子串的最右侧字符索引
    // right-middle+1
    for (int i = 0; i < transform.size(); ++i) {
        if (i < maxSubRight) {
            int j = 2*maxSubMiddle - i;
            if (palindromeLen[j] < maxSubRight - i) {
                palindromeLen[i] = palindromeLen[j];
            } else {
                palindromeLen[i] = maxSubRight - i + 1;
            }
        } else {
            palindromeLen[i] = 1;
        }

        //transform[i]两端开始扩展匹配，直到匹配失败时停止
        while (i - palindromeLen[i] >= 0
               && i + palindromeLen[i] < transform.size()
               && transform[i - palindromeLen[i]] == transform[i + palindromeLen[i]]) {
            palindromeLen[i] += 1;
        }

        //匹配的新回文子串长度大于原有最大的长度
        if (palindromeLen[i] > palindromeLen[maxSubMiddle]) {
            maxSubRight = palindromeLen[i] + i - 1;
            maxSubMiddle = i;
        }
    }

    // maxSubRight - maxSubMiddle即为增量字符串回文的半径，所以相当于原始字符串的最长回文长度
    int maxPalindromeLength = maxSubRight - maxSubMiddle;// ->palindromeLen[maxSubMiddle] - 1

    // 原始字符串最长回文子串的起始位置索引 = （（maxSubMiddle - 1）- palindromeLen[maxSubMiddle]）/ 2
    // (maxSubMiddle - 1 - palindromeLen[maxSubMiddle])/2 => (2*maxSubMiddle - maxSubRight)/2
    return src.substr((2*maxSubMiddle - maxSubRight)/2, maxPalindromeLength);
}

std::string CPalindrome::centreSpread(const std::string &src) {
    this->maxPalindromeLength = 0;
    for (int i = 0; i < src.size(); ++i) {
        // 偶数，双核回文
        longestPalindrome(src, i - 1, i);
        // 奇数，单核回文
        longestPalindrome(src, i, i);
    }

    return this->longestPalindromeStr;
}


void CPalindrome::longestPalindrome(const std::string &src, int low, int high) {
    while (low <= high && low >= 0 && high < src.size()) {
        if (src[low] == src[high]) {
            int max = high - low + 1;
            if (max > this->maxPalindromeLength) {
                this->maxPalindromeLength = max;
                this->longestPalindromeStr = src.substr(low, this->maxPalindromeLength);
            }

            low--;
            high++;
        } else {
            break;
        }
    }
}