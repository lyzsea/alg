//
// Created by yz L on 2019-09-09.
//

#include <vector>
#include "../header/removeDuplicatesChar.h"

std::string CRemoveDuplicates::removeDuplicates(const std::string& src) {
    std::string result = "";
    for (char ch: src) {
        if (result.empty() || ch != result.back()) {
            result.push_back(ch);
        } else {
            result.pop_back();
        }
    }

    return result;
}

std::string CRemoveDuplicates::removeDuplicatesOrigin(std::string src) {
    int count =0;
    for (char ch: src) {
        if (count == 0 || ch != src[count-1]) {
            src[count++] = ch;
        } else {
            count--;
        }
    }
    src.resize(count);
    return src;
}