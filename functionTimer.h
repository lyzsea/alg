//
// Created by yz L on 2019-05-17.
//

#ifndef ALG_FUNCTIONTIMER_H
#define ALG_FUNCTIONTIMER_H

#include <string>
#include <chrono>

using namespace std::chrono;

class CFunctionTimer {
public:
    CFunctionTimer();
    CFunctionTimer(std::string functionName);
    ~CFunctionTimer();

private:
    std::string functionName;
    steady_clock::time_point startTime;
    steady_clock::time_point endTime;
};
#endif //ALG_FUNCTIONTIMER_H
