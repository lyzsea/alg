//
// Created by yz L on 2019-06-20.
//

#ifndef ALG_LONGCOMMSUBSTRING_H
#define ALG_LONGCOMMSUBSTRING_H

#include <string>

#include "singleton.h"

class CLongCommString {
    friend class CSingleton<CLongCommString> ;

public:
    enum ALG_TYPE {
        MATRIX = 0,// 二维数组矩阵
        RECURSIVE, // 递归
        DY_PLAN, //动态规划
    }; // 定义算法实现类型

public:
    /**
     * find两字符串的最长公共子串
     * @param firstStr
     * @param secondStr
     * @return
     */
    std::string findLongestCommString(const std::string &firstStr,
                                      const std::string &secondStr, ALG_TYPE algType = MATRIX);

    /**
     * find两字符串的最长公共子序列
     * @return
     */
    std::string findLongestCommSequence(const std::string &firstStr,
                                        const std::string &secondStr, ALG_TYPE algType = MATRIX);

    /**
     * 最长公共子序列长度
     * @param firstStr
     * @param secondStr
     * @param algType
     * @return
     */
    int lengthOfCommSequence(const std::string &firstStr,
                             const std::string &secondStr, ALG_TYPE algType = RECURSIVE);

private:
    /**
     * 二维数组作为矩阵实现,时间复杂度O(MN)
     * @param firstStr
     * @param secondStr
     * @return
     */
    std::string commStringByMatrix(const std::string& firstStr, const std::string& secondStr);

    /**
     * 递归实现
     * @param firstStr
     * @param secondStr
     * @return
     */
    std::string commSequenceByMatrix(const std::string& firstStr, const std::string& secondStr);

    /**
     * 递归实现最长公共子序列
     * @param i
     * @param j
     * @return
     */
    int LCSLengthByRecursive(int i, int j, const std::string &firstStr, const std::string &secondStr);

    /**
     * 构造矩阵，利用动态规划思想
     * @param firstStr
     * @param secondStr
     * @return
     */
    int LCSLengthByMatrix(const std::string &firstStr, const std::string &secondStr);
};
#endif //ALG_LONGCOMMSUBSTRING_H
