//
// Created by yz L on 2019-03-16.
//
#include <list>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

#include "../header/hostCrowding.h"


std::vector<std::string> CHostCrowding::paginate(int perpageCount,const std::vector<std::string>& src) {
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




