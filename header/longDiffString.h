//
// Created by yz L on 2019-06-18.
//

#ifndef ALG_LONGCOMMSTRING_H
#define ALG_LONGCOMMSTRING_H

/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 */

/* unit test
 * std::string testStr = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   std::cout << "len0: " << lengthOfLongestSubstring2(testStr) << std::endl;
   std::cout << "len1: " << lengthOfLongestSubstring2("dvdf") << std::endl;
   std::cout << "len2: " << lengthOfLongestSubstring2("##b") << std::endl;
   std::cout << "len3: " << lengthOfLongestSubstring2("wpwwef") << std::endl;
   std::cout << "len4: " << lengthOfLongestSubstring2("$$$$$") << std::endl;
   std::cout << "len5: " << lengthOfLongestSubstring2("abcabcbf") << std::endl;
*/
#include <string>

class CLongDiffString {
public:
    enum ALG_TYPE {
        COMMON = 0,//两层循环判断
        HASH, // 利用assic码值有限区间
        DY_PLAN, //动态规划
    }; // 定义算法实现类型
public:
    /**
     * 寻找无重复字符的最长子串
     * @param src
     * @param alg_type
     * @return
     */
    std::string longestDiffSubstring(const std::string& src,ALG_TYPE alg_type=ALG_TYPE::HASH);
private:
    /**
     * 使用set记录已经出现过的字符，时间复杂度 256N
     * @param src
     * @return
     */
    std::string commonTraverse(const std::string& src);
    /**
     * 利用assic码值有限区间，用ascii code值作为hash数组索引，省去对已遍历非重复字符的再次遍历
     * @param src
     * @return
     */
    std::string asciiCodeHash(const std::string& src);
};
#endif //ALG_LONGCOMMSTRING_H
