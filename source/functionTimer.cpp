//
// Created by yz L on 2019-05-17.
//
#include <iostream>
#include "../header/functionTimer.h"

CFunctionTimer::CFunctionTimer() {
    this->startTime = steady_clock::now();
}

CFunctionTimer::CFunctionTimer(std::string functionName) {
    this->functionName = functionName;
    this->startTime = steady_clock::now();
}

CFunctionTimer::~CFunctionTimer() {
    steady_clock::time_point endTime = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(endTime - startTime);
    std::cout <<std::endl;
    std::cout << this->functionName << " exec spent time: "<<time_span.count()*1000 << " ms"<<std::endl;
}
