#include <iostream>
#include <string>
using namespace std;
#include <gtest/gtest.h>

#include "commonHeaders.h"

template <class T>
void print(T n) {
    std::cout<<n<<", ";
}

TEST(testtwoSumToTarget,twoSumToTarget) {
    std::cout<<"两数之和等于target"<<endl;
    CTwoSumToTarget instance = CSingleton<CTwoSumToTarget>::getInstance();
    std::vector<int> src = {2, 7, 11, 15};
    std::vector<int> result = instance.twoSumToTarget(src,9);
    for_each(result.begin(),result.end(),&print<int>);
}

TEST(testSortArrayMedain,findMedianSortedArrays) {
    std::cout<<"两个排序数组的中位数"<<std::endl;
    CMedianSortArray instance = CSingleton<CMedianSortArray>::getInstance();
    std::vector<int> num1 = {1,3};
    std::vector<int> num2 = {2,4};
    cout<<"median: "<< instance.findMedianSortedArrays(num1,num2);
}

TEST(testminDistanceToChar,getMinDistanceArray) {
    std::cout<<"字符串各字符到目标字符的最短距离"<<endl;
    const std::string src = "lovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydata";

    CMinDistanceToChar instance =  CSingleton<CMinDistanceToChar>::getInstance();

    std::vector<int> resultVec = instance.getMinDistanceArray(src, 'e');
    for_each(resultVec.begin(), resultVec.end(), &print<int>);

    std::vector<int> resultVecSecond = instance.getMinDistanceArray(src, 'e',CMinDistanceToChar::ALG_TYPE::NORMAL);
    for_each(resultVecSecond.begin(), resultVecSecond.end(), &print<int >);
}

TEST(testPalindrome,findLongestPalindrome) {
    std::cout<<"查找最长回文"<<endl;
    const std::string src ="ababcbaeffeabc";
    CPalindrome instance = CSingleton<CPalindrome>::getInstance();
    std::string longestPalindromeStr = instance.findLongestPalindrome(src,
                                                                      CPalindrome::ALG_TYPE::CENTRE_SPREAD);
    std::cout << longestPalindromeStr << endl;

    longestPalindromeStr = instance.findLongestPalindrome(src);
    std::cout << longestPalindromeStr << endl;
}

TEST(testHostCrowding,paginate) {
    std::cout<<"hostCrowding"<<std::endl;
    std::vector<std::string> src;
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
    CHostCrowding instance = CSingleton<CHostCrowding>::getInstance();

    std::vector<std::string> result = instance.paginate(5,src);
    for (auto itor = result.begin(); itor != result.end(); ++itor) {
        std::cout<<*itor<<std::endl;
    }
}

TEST(testLongestDiffString,longestDiffSubstring) {
    std::cout<<"最长非重复子串"<<endl;
    CLongDiffString instance = CSingleton<CLongDiffString>::getInstance();
    std::string testStr = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::cout << "0: " << instance.longestDiffSubstring(testStr) << std::endl;
    std::cout << "1: " << instance.longestDiffSubstring("dvdf") << std::endl;
    std::cout << "2: " << instance.longestDiffSubstring("##b") << std::endl;
    std::cout << "3: " << instance.longestDiffSubstring("wpwwef") << std::endl;
    std::cout << "4: " << instance.longestDiffSubstring("$$$$$") << std::endl;
    std::cout << "5: " << instance.longestDiffSubstring("abcabcbf") << std::endl;
}

TEST(testLongCommString,findLongestCommString) {
    std::cout <<"最长公共子串"<<std::endl;

    CLongCommString instance = CSingleton<CLongCommString>::getInstance();
    std::cout << "1: " << instance.findLongestCommString("xxabcd", "abcd") << std::endl;
    std::cout << "2: " << instance.findLongestCommString("abc", "cdef") << std::endl;
}

TEST(testLongCommString,lengthOfCommSequence) {
    std::cout <<"最长公共子序列长度"<< std::endl;

    CLongCommString instance = CSingleton<CLongCommString>::getInstance();
    std::cout << "length: " << instance.lengthOfCommSequence("xxaybycyd", "azbzczdz") << std::endl;
    std::cout << "length: " << instance.lengthOfCommSequence("abc", "acdef") << std::endl;
}

TEST(testLongCommString,findLongestCommSequence) {
    std::cout <<"最长公共子序列"<< std::endl;

    CLongCommString instance = CSingleton<CLongCommString>::getInstance();
    std::cout << "common sequence: " << instance.findLongestCommSequence("xxaybycyd", "azbzczdz") << std::endl;
    std::cout << "common sequence: " << instance.findLongestCommSequence("abc", "acdef") << std::endl;
}

TEST(testZigzagConversion,zigzagConvert) {
    std::cout <<"锯齿输出字符串"<< std::endl;
    CZigzagConversion instance = CSingleton<CZigzagConversion>::getInstance();
    std::string src = "PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRIN"
                      "PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRING";
    instance.zigzagConvert(src,3);
    instance.zigzagConvert(src,3,CZigzagConversion::ALG_TYPE::CALC_ROW_INDEX);
    /*std::cout<<"zigzag output: "<<instance.zigzagConvert("PAYPALISHIRING",3) << ", result: PAHNAPLSIIGYIR"<<std::endl;
    std::cout<<"zigzag output: "<<instance.zigzagConvert("PAYPALISHIRING",4) << ", result: PINALSIGYAHRPI"<<std::endl;*/
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}