//
// Created by yz L on 2019-03-21.
//
#include "palindrome.h"

int maxPalindromeLength = 0;
std::string longestPalindromeStr = "";


void longestPalindrome(const std::string &src, int low, int high);

std::string longestPalindrome(const std::string &src) {
    for (int i = 0; i < src.size(); ++i) {
        // 偶数
        longestPalindrome(src, i - 1, i);
        // 奇数
        longestPalindrome(src, i, i);
    }

    return longestPalindromeStr;
}


void longestPalindrome(const std::string &src, int low, int high) {
    while (low <= high && low >= 0 && high < src.size()) {
        if (src[low] == src[high]) {
            int max = high - low + 1;
            if (max > maxPalindromeLength) {
                maxPalindromeLength = max;
                longestPalindromeStr = src.substr(low, maxPalindromeLength);
            }

            low--;
            high++;
        } else {
            break;
        }
    }
}