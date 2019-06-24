cmake_minimum_required(VERSION 3.13)
project(alg)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_DIR /usr/local/include)
set(LIB_DIR /usr/local/lib)

include_directories(${INCLUDE_DIR})
link_directories(${LIB_DIR})
link_libraries(gtest)

find_package(GTEST REQUIRED)

add_executable(alg main.cpp hostCrowding.cpp numSum.cpp ListNode.h median.cpp source/longDiffString.cpp source/palindrome.cpp header/commonHeaders.h source/minDistanceToChar.cpp header/functionTimer.h source/functionTimer.cpp header/palindrome.h header/singleton.h header/longDiffString.h header/longCommString.h source/longCommString.cpp header/minDistanceToChar.h)

target_link_libraries(${PROJECT_NAME} gtest)