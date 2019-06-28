//
// Created by yz L on 2019-06-24.
//

/**
 * 6. The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
 */

#ifndef ALG_ZIGZAGCONVERSION_H
#define ALG_ZIGZAGCONVERSION_H

#include <string>

#include "singleton.h"
class CZigzagConversion {
    friend class CSingleton<CZigzagConversion>;

public:
    enum ALG_TYPE {
        NORMAL,// 模拟锯齿变形过程, 高效一些
        CALC_ROW_INDEX,// 通过规律计算，相比增加了函数调用开销
    };
public:
    std::string zigzagConvert(const std::string& src, int rows, ALG_TYPE algType=NORMAL);

private:
    std::string zigzagConvertNormal(const std::string& src, int rows);

    std::string zigzagConvertCalcRowIndex(const std::string& src, int rows);
    /**
     * get the index of zigzag array.
     * @param charPosition
     * @param rows
     * @return
     */
    int getRowIndex(int charPosition, int rows);
};
#endif //ALG_ZIGZAGCONVERSION_H
