cmake_minimum_required(VERSION 3.13)
project(alg)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_DIR /usr/local/include)
set(LIB_DIR /usr/local/lib)

include_directories(${INCLUDE_DIR})
link_directories(${LIB_DIR})
link_libraries(gtest)

find_package(GTEST REQUIRED)

add_executable(alg main.cpp source/hostCrowding.cpp source/twoSumToTarget.cpp header/listReverse.h source/sortArrayMedian.cpp source/longDiffString.cpp source/palindromeString.cpp commonHeaders.h source/minDistanceToChar.cpp header/functionTimer.h source/functionTimer.cpp header/palindromeString.h header/singleton.h header/longDiffString.h header/longCommString.h source/longCommString.cpp header/minDistanceToChar.h header/zigzagConversion.h source/zigzagConversion.cpp header/twoSumToTarget.h header/sortAarrayMedian.h header/hostCrowding.h header/reverseInteger.h header/stringToInt.h header/palindromeInteger.h)

target_link_libraries(${PROJECT_NAME} gtest)