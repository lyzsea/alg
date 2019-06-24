//
// Created by yz L on 2019-06-24.
//

#ifndef ALG_MINDISTANCETOCHAR_H
#define ALG_MINDISTANCETOCHAR_H
#include <string>
#include <vector>

#include "singleton.h"

class CMinDistanceToChar {
    friend class CSingleton<CMinDistanceToChar> ;

public:
    enum ALG_TYPE {
       BINARY_SEARCH,
       NORMAL,
    }; // 定义算法实现类型
public:
    std::vector<int> getMinDistanceArray(const std::string& src, char target,ALG_TYPE algType = BINARY_SEARCH);
private:
    /**
     * 子数组利用二分查找实现,更高效
     * @param src
     * @param target
     * @return
     */
    std::vector<int> getCharMinDistanceBinarySearch(const std::string& src, char target);

    /**
     * 正常思路，顺序遍历查找
     * @param src
     * @param target
     * @return
     */
    std::vector<int> getCharMinDistanceNormal(const std::string& src, char target);

    /**
     * 二分查找实现
     * @param curIndex
     * @param targetIndexVec
     * @return
     */
    int getMinDistanceBinarySearch(int curIndex, const std::vector<int> &targetIndexVec);

    /**
     * 正常思路，顺序遍历查找
     * @param curIndex
     * @param startItor
     * @param targetIndexVec
     * @return
     */
    int getMinDistanceNormal(int curIndex,
                             std::vector<int>::const_iterator startItor,
                             const std::vector<int> &targetIndexVec);
};
#endif //ALG_MINDISTANCETOCHAR_H
