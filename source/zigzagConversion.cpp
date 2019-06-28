//
// Created by yz L on 2019-06-27.
//

#include <vector>
#include <sstream>
#include "../header/zigzagConversion.h"
#include "../header/functionTimer.h"

std::string CZigzagConversion::zigzagConvert(const std::string& src, int rows, ALG_TYPE algType) {
    switch (algType) {
        case NORMAL:
            return zigzagConvertNormal(src,rows);
        case CALC_ROW_INDEX:
            return zigzagConvertCalcRowIndex(src,rows);
        default:
            return zigzagConvertNormal(src,rows);
    }
}

std::string CZigzagConversion::zigzagConvertNormal(const std::string &src, int rows) {
    CFunctionTimer timer(__FUNCTION__);
    if (rows == 1) {
        return src;
    }

    std::vector<std::string> zigzagRows(rows);

    int cunRowIndex = 0;
    bool isGoDown = false;
    for (char ch: src) {
        zigzagRows[cunRowIndex] += ch;

        if (cunRowIndex == 0 || cunRowIndex == rows -1) {
            isGoDown = !isGoDown;
        }

        cunRowIndex += isGoDown?1:-1;
    }

    std::string output;
    for (std::string rowStr: zigzagRows) {
        output += rowStr;
    }

    return output;
}

std::string CZigzagConversion::zigzagConvertCalcRowIndex(const std::string &src, int rows) {
    CFunctionTimer timer(__FUNCTION__);
    if (rows == 1) {
        return src;
    }
    // 每一行记录锯齿形字符串的行字符
    std::vector<std::string> zigzagVecList(rows);

    for (int i = 1; i <= src.size(); ++i) {
        zigzagVecList[getRowIndex(i,rows)] += src[i-1];
    }

    std::string output = zigzagVecList[0];
    for (int j = 1; j < rows; ++j) {
        output += zigzagVecList[j];
    }

    return output;
}

int CZigzagConversion::getRowIndex(int charPosition, int rows) {
    if (charPosition <= rows) {
        return charPosition - 1;
    }

    // 一个非重复锯齿形状的长度为： 行数*2 - 首尾两行
    int mod = charPosition % (rows * 2 - 2);

    // 0特殊处理,必定在第二行
    if (mod == 0) {
        return 1;// 2 - 1
    }

    if (mod <= rows) {
        return mod -1;
    } else {
        // (row - x) *2 + x = mod
        return 2*rows - mod -1;
    }
}



