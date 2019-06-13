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


#include "commonHeaders.h"
#include "header/palindrome.h"

/**
 *
 * @param src
 * @param algType
 * @return
 */
std::string CPalindrome::findLongestPalindrome(const std::string& src,ALG_TYPE algType) {
    this->maxPalindromeLength = 0;
    switch (algType) {
        case ALG_TYPE::CENTRE_SPREAD :
            this->longestPalindromeStr = centreSpread(src);
            break;
        case ALG_TYPE::MANACHER :
            this->longestPalindromeStr = manacher(src);
            break;
        default:
            this->longestPalindromeStr = manacher(src);
            break;
    }

    return this->longestPalindromeStr;
}

std::string CPalindrome::manacher(const std::string &src) {
    std::string transform(src.size()*2+1,'#');
    for (int i = 0; i < transform.size(); ++i) {
        if (i%2 == 1) {
            transform[i] = src[(i+1)/2-1];
        }
    }

    std::vector<int> palindromeLen(transform.size(), 0);
    int maxSubMiddle =0;
    int maxSubRight = 0;
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

        while (i - palindromeLen[i] >= 0
               && i + palindromeLen[i] < transform.size()
               && transform[i - palindromeLen[i]] == transform[i + palindromeLen[i]]) {
            palindromeLen[i] += 1; //transform[i]两端开始扩展匹配，直到匹配失败时停止
        }

        //匹配的新回文子串长度大于原有的长度
        if (palindromeLen[i] >= palindromeLen[maxSubMiddle]) {
            maxSubRight = palindromeLen[i] + i - 1;
            maxSubMiddle = i;
        }
    }

    this->maxPalindromeLength = maxSubRight - maxSubMiddle;

    return src.substr((2*maxSubMiddle - maxSubRight)/2, this->maxPalindromeLength);
}

std::string CPalindrome::centreSpread(const std::string &src) {
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