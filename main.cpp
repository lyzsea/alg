#include <iostream>
#include <string>
#include <random>
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
    EXPECT_EQ(instance.findMedianSortedArrays(num1, num2), 2.5);
    num1 = {1,2};
    num2 = {-1,3};
    EXPECT_EQ(instance.findMedianSortedArrays(num1, num2), 1.5);
}

TEST(testminDistanceToChar,getMinDistanceArray) {
    std::cout<<"字符串各字符到目标字符的最短距离"<<endl;
    const std::string src = "lovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwtaibenledatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydatalovewwwejoydata";

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
    EXPECT_EQ(instance.longestDiffSubstring(testStr), "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    EXPECT_EQ(instance.longestDiffSubstring("dvdf"), "vdf");
    EXPECT_EQ(instance.longestDiffSubstring("##b"), "#b");
    EXPECT_EQ(instance.longestDiffSubstring("wpwwef"), "wef");
    EXPECT_EQ(instance.longestDiffSubstring("$$$$$"), "$");
    EXPECT_EQ(instance.longestDiffSubstring("abcabcbf"), "cbf");
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
    std::cout <<"zigzag string"<< std::endl;
    CZigzagConversion instance = CSingleton<CZigzagConversion>::getInstance();
    std::string src = "PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRIN"
                      "PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRING";
    instance.zigzagConvert(src,3);
    instance.zigzagConvert(src,3,CZigzagConversion::ALG_TYPE::CALC_ROW_INDEX);
    EXPECT_EQ(instance.zigzagConvert("PAYPALISHIRING",3) ,"PAHNAPLSIIGYIR");
    EXPECT_EQ(instance.zigzagConvert("PAYPALISHIRING",4) ,"PINALSIGYAHRPI");
}

TEST(testListReverse,reverse) {
    std::cout << "list reverse " << std::endl;
    ListNode<int> *node1 = new ListNode<int>(1);
    ListNode<int> *node2 = new ListNode<int>(2);
    ListNode<int> *node3 = new ListNode<int>(3);
    ListNode<int> *node4 = new ListNode<int>(4);
    ListNode<int> *node5 = new ListNode<int>(5);
    ListNode<int> *node6 = new ListNode<int>(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    ListNode<int> *pHeader = node1;
    CListReverse instance = CSingleton<CListReverse>::getInstance();
    instance.printList(pHeader);
    ListNode<int> *pReverse = instance.reverse(pHeader);
    instance.printList(pReverse);

    pHeader = instance.reverseKGroup(pReverse,3);
    instance.printList(pHeader);
}

TEST(testreverseInteger,reverseInteger) {
    std::cout <<"reverse integer"<< std::endl;
    CReverseInteger instance = CSingleton<CReverseInteger>::getInstance();
    EXPECT_EQ(instance.reverseInteger(123),321);
    EXPECT_EQ(instance.reverseInteger(-123),-321);
    EXPECT_EQ(instance.reverseInteger(120),21);
}

TEST(testpalindromeInteger, isPalindrome) {
    std::cout << "palindrome integer" << std::endl;
    CPalindromeInteger instance = CSingleton<CPalindromeInteger>::getInstance();
    EXPECT_EQ(instance.isPalindrome(121), true);
    EXPECT_EQ(instance.isPalindrome(10), false);
    EXPECT_EQ(instance.isPalindrome(-121), false);
    EXPECT_EQ(instance.isPalindrome(12121), true);
}

TEST(teststringToInt,myAtoi) {
    std::cout<<"atoi"<<std::endl;
    CStringToInt instance = CSingleton<CStringToInt>::getInstance();
    EXPECT_EQ(instance.myAtoi("123"),123);
    EXPECT_EQ(instance.myAtoi("  -123"),-123);
    EXPECT_EQ(instance.myAtoi("4193 with words"),4193);
    EXPECT_EQ(instance.myAtoi("words and 987"),0);
    EXPECT_EQ(instance.myAtoi("-91283472332"),INT_MIN);
}

TEST(shareTopicRandom,random) {
    std::string shareTopicNames[] = {"","", "","",""};
    std::string bizShareNames[] = {"","","",""};


    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> u(0, 9); //随机数分布对象
    for (size_t i = 0; i < 10; ++i)  //生成范围为0-9的随机数序列
        cout << u(e) << " ";
    cout << endl;

}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}