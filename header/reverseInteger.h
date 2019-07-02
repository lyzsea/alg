//
// Created by yz L on 2019-06-30.
//
/**
 * 7. Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

https://leetcode-cn.com/problems/reverse-integer
 */
#ifndef ALG_REVERSEINTEGER_H
#define ALG_REVERSEINTEGER_H

#include <climits>
#include <cmath> //std::abs()
#include "singleton.h"


class CReverseInteger {
public:
    int reverseInteger(int src) {
        int output = 0;
        while(src !=0) {
            int mod = src % 10;
            src /= 10;
            if (output > INT_MAX /10 || (output == INT_MAX/10 && mod >7)) {
                return 0;
            }
            if (output < INT_MIN/10 || (output == INT_MIN/10 && mod < -8)) {
                return 0;
            }
            output = output*10 + mod;
        }

        return output;
    }
};
#endif //ALG_REVERSEINTEGER_H
