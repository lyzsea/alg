//
// Created by yz L on 2019-06-08.
//

#ifndef ALG_PALINDROME_H
#define ALG_PALINDROME_H

#include <string>

#include "singleton.h"

class CPalindrome {
    friend class CSingleton<CPalindrome> ;
public:
    enum ALG_TYPE {
        MANACHER = 0,
        CENTRE_SPREAD
    }; // 定义算法实现类型
public:
    std::string findLongestPalindrome(const std::string &src, ALG_TYPE algType = ALG_TYPE::MANACHER);
private:
    /**
     * 中心扩散find最长回文，时间复杂度: O(n^2)
     * @param src
     * @return
     */
    std::string centreSpread(const std::string &src);

    /**
     * 中心扩散判断回文，基于当前字符判断（low=high为单核，差一为双核）
     * @param src
     * @param low
     * @param high
     */
    void longestPalindrome(const std::string &src, int low, int high);

    /**
     * 马拉车算法，时间复杂度: O(n)
     * @param src
     * @return
     */
    std::string manacher(const std::string& src);
private:
    int maxPalindromeLength;
    std::string longestPalindromeStr;
};
#endif //ALG_PALINDROME_H
