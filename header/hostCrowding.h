//
// Created by yz L on 2019-06-29.
//

/* 第一列去重，按顺序显示，指定行数显示一行空格
 * 测试代码
 *  std::vector<std::string> src;
    src.push_back("1,28,310.6,SF");
    src.push_back("4,5,204.1,SF");
    src.push_back("20,7,203.2,Oakland");
    src.push_back("6,8,202.2,SF");
    src.push_back("6,10,199.1,SF");
    src.push_back("1,16,190.4,SF");
    src.push_back("6,29,185.2,SF");
    src.push_back("7,20,180.1,SF");
    src.push_back("6,21,162.1,SF");
    src.push_back("2,30,149.1,SF");
    src.push_back("3,76,146.2,SF");
    src.push_back("2,14,141.1,San Jose");
    std::vector<std::string> result = paginate(5,src);
    for (auto itor = result.begin(); itor != result.end(); ++itor) {
        std::cout<<*itor<<std::endl;
    }
*/
#ifndef ALG_HOSTCROWDING_H
#define ALG_HOSTCROWDING_H
#include <vector>

class CHostCrowding {


public:
    std::vector<std::string> paginate(int perpageCount,const std::vector<std::string>& src);
};
#endif //ALG_HOSTCROWDING_H
