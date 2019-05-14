//
// Created by yz L on 2019-05-10.
//

#ifndef ALG_CHARMINDISTINCE_H
#define ALG_CHARMINDISTINCE_H

#include <vector>
#include <string>

/**
 *
 * @param src
 * @param target
 * @return
 */
std::vector<int> getCharMinDistance(const std::string& src, const char target);

/**
 *
 * @param perpageCount
 * @param src
 * @return
 */
std::vector<std::string> paginate(int perpageCount,const std::vector<std::string>& src);

/**
 *
 * @param s
 * @return
 */
std::string longestPalindrome(const std::string& s);

/**
 *
 * @param s
 * @return
 */
int lengthOfLongestSubstring(std::string s);
int lengthOfLongestSubstring2(std::string s);

/**
 *
 * @param nums1
 * @param nums2
 * @return
 */
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2);

/**
 *
 * @param nums
 * @param target
 * @return
 */
std::vector<int> twoSum(std::vector<int>& nums, int target);

#endif //ALG_CHARMINDISTINCE_H
