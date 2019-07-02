//
// Created by yz L on 2019-06-30.
//
/**
 * 9. Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

https://leetcode-cn.com/problems/palindrome-number
 */
#ifndef ALG_PALINDROMEINTEGER_H
#define ALG_PALINDROMEINTEGER_H

class CPalindromeInteger {
public:
    /**
     * reverse itself and then compare to origin value, palindrome integer is same.
     * @param src
     * @return
     */
    bool isPalindrome(int src) {
        if (src < 0) {
            return false;
        }

        int origin = src;
        int reverse = 0;
        while (src != 0) {
            reverse = reverse * 10 + src % 10;
            src /= 10;
        }

        return origin == reverse;
    }
};

#endif //ALG_PALINDROMEINTEGER_H
