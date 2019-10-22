//
// Created by yz L on 2019-10-17.
//
/**
 * 260. Single Number III
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
 * Find the two elements that appear only once.

 Example:
    Input:  [1,2,1,3,2,5]
    Output: [3,5]

 Note:
 1.The order of the result is not important. So in the above example, [5, 3] is also correct.
 2.Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

 * https://leetcode-cn.com/problems/single-number-iii
 */

#ifndef ALG_TWOSINGLENUMBER_H
#define ALG_TWOSINGLENUMBER_H

#include <vector>
class CTwoSingleNumbers {
public:
    std::vector<int> singleNumber(std::vector<int>& nums);

private:
    int findFirstOneIndex(int num);
    bool isBitOne(int num,int indexForOne);
};
#endif //ALG_TWOSINGLENUMBER_H
