//
// Created by yz L on 2019-06-20.
//
#include "../header/longCommString.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

/**
 * find最长公共子串
 * @param firstStr
 * @param secondStr
 * @param algType
 * @return
 */
std::string CLongCommString::findLongestCommString(const std::string &firstStr,
                                                   const std::string &secondStr, ALG_TYPE algType) {
    switch (algType) {
        case ALG_TYPE::MATRIX :
            return commStringByMatrix(firstStr, secondStr);
        case ALG_TYPE::RECURSIVE :
            break;
        default:
            return commStringByMatrix(firstStr, secondStr);
    }
}

std::string CLongCommString::findLongestCommSequence(const std::string &firstStr,
                                                     const std::string &secondStr, ALG_TYPE algType) {
    switch (algType) {
        case ALG_TYPE::MATRIX :
            return commSequenceByMatrix(firstStr, secondStr);
        case ALG_TYPE::RECURSIVE :
            break;
        default:
            return commSequenceByMatrix(firstStr, secondStr);
    }
}

int CLongCommString::lengthOfCommSequence(const std::string &firstStr,
                                          const std::string &secondStr, ALG_TYPE algType) {
    switch (algType) {
        case ALG_TYPE::MATRIX :
            return LCSLengthByMatrix(firstStr, secondStr);
        case ALG_TYPE::RECURSIVE :
            return LCSLengthByRecursive(firstStr.size() - 1, secondStr.size() - 1, firstStr, secondStr);
        default:
            break;
    }
}

std::string CLongCommString::commStringByMatrix(const std::string &firstStr, const std::string &secondStr) {
    if (firstStr.empty() || secondStr.empty()) {
        return "";
    }

    std::vector<std::vector<int>> matrix(firstStr.size());
    for (int k = 0; k < matrix.size(); ++k) {
        matrix[k].resize(secondStr.size(), 0);
    }
    int maxLength = 0;
    int indexForMax = 0;
    for (int i = 0; i < firstStr.size(); ++i) {
        for (int j = 0; j < secondStr.size(); ++j) {
            if (firstStr[i] != secondStr[j]) {
                continue;
            }
            matrix[i][j] = i > 0 && j > 0 ? (matrix[i - 1][j - 1] + 1) : 1;
            if (matrix[i][j] > maxLength) {
                maxLength = matrix[i][j];
                indexForMax = i;
            }
        }
    }

    return maxLength > 0 ? firstStr.substr(indexForMax - maxLength + 1, maxLength) : "";
}

std::string CLongCommString::commSequenceByMatrix(const std::string &firstStr, const std::string &secondStr) {
    std::vector<std::vector<int>> matrix(firstStr.size() + 1);
    for (int k = 0; k < matrix.size(); ++k) {
        matrix[k].resize(secondStr.size() + 1, 0);
    }

    for (int i = 1; i <= firstStr.size(); ++i) {
        for (int j = 1; j <= secondStr.size(); ++j) {
            if (firstStr[i -1] == secondStr[j -1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else if(matrix[i-1][j] > matrix[i][j-1]) {
                matrix[i][j] = matrix[i-1][j];
            } else {
                matrix[i][j] = matrix[i][j-1];
            }
        }
    }

    std::stringstream commSequenceStream;
    int i = firstStr.size(), j = secondStr.size();
    while (i != 0 && j!=0) {
        if (firstStr[i-1] == secondStr[j-1]) {
            commSequenceStream<<firstStr[i-1];
            --i;
            --j;
        } else if (matrix[i-1][j] < matrix[i][j-1]) {
            j--;
        } else {
            i--;
        }
    }

    std::string commSequence = commSequenceStream.str();
    std::reverse(commSequence.begin(),commSequence.end());

    return commSequence;
}

int CLongCommString::LCSLengthByRecursive(int i, int j,
                                          const std::string &firstStr, const std::string &secondStr) {
    if (i == 0 || j == 0) {
        return firstStr[i] == secondStr[j] ? 1 : 0;
    }

    if (firstStr[i] == secondStr[j]) {
        return LCSLengthByRecursive(i - 1, j - 1, firstStr, secondStr) + 1;
    } else {
        return std::max(LCSLengthByRecursive(i - 1, j, firstStr, secondStr),
                        LCSLengthByRecursive(i, j - 1, firstStr, secondStr));
    }
}

int CLongCommString::LCSLengthByMatrix(const std::string &firstStr, const std::string &secondStr) {
    // 二维数组初始化为字符串长度+1，避免后续索引为0的边界判断
    std::vector<std::vector<int>> matrix(firstStr.size() + 1);
    for (int k = 0; k < matrix.size(); ++k) {
        matrix[k].resize(secondStr.size() + 1, 0);
    }

    int maxLength = 0;
    for (int i = 1; i <= firstStr.size(); ++i) {
        for (int j = 1; j <= secondStr.size(); ++j) {
            if (firstStr[i -1] == secondStr[j -1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else if(matrix[i-1][j] > matrix[i][j-1]) {
                matrix[i][j] = matrix[i-1][j];
            } else {
                matrix[i][j] = matrix[i][j-1];
            }

            maxLength = std::max(maxLength,matrix[i][j]);
        }
    }

    return maxLength;
}
