#include <iostream>
#include <unordered_set>
#include<time.h>

using namespace std;

#include "hostCrowding.h"
#include "numSum.h"
#include "ListNode.h"
#include "median.h"
#include "longSubString.h"
#include "palindrome.h"

int main() {

    std::string src = "aabbaa";
    std::string longestPalindromeStr = longestPalindrome(src);

    std::cout<<longestPalindromeStr<<endl;
    return 0;
}