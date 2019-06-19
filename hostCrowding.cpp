//
// Created by yz L on 2019-03-16.
//
#include <list>
#include <unordered_map>
#include "header/commonHeaders.h"

/* 测试代码
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

std::vector<std::string> paginate(int perpageCount,const std::vector<std::string>& src) {
    std::list<std::pair<int,int>> hostIds;
    for (int i = 0; i < src.size(); ++i) {
        const std::string& srcItem =src[i];
        hostIds.emplace_back(std::make_pair(std::stoi(srcItem.substr(0,srcItem.find_first_of(','))),i));
    }

    std::vector<std::string> outputVec;

    int count =0;
    std::unordered_map<int,int> uniqueHostIds;
    for (auto itor = hostIds.begin(); itor != hostIds.end();) {
        if (uniqueHostIds.find(itor->first) == uniqueHostIds.end()) {
            uniqueHostIds.insert(std::make_pair(itor->first,itor->second));
            count++;
            outputVec.push_back(src[itor->second]);
            itor = hostIds.erase(itor);
            std::list<std::pair<int,int>>::iterator judgeItor = itor;
            if (count == perpageCount && (++judgeItor) != hostIds.end()) {
                outputVec.push_back("");
                count = 0;
            }
        } else {
            ++itor;
        }
    }

    auto itor = hostIds.begin();
    for (int j = outputVec.size(); j < perpageCount && itor != hostIds.end(); ++j) {
        outputVec.push_back(src[itor->second]);
        ++itor;
    }

    return outputVec;
}




