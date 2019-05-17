//
// Created by yz L on 2019-03-21.
//
#include <unordered_set>

#include "commonHeaders.h"

/* test
 * std::string testStr = "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   std::cout << "len0: " << lengthOfLongestSubstring2(testStr) << std::endl;
   std::cout << "len1: " << lengthOfLongestSubstring2("dvdf") << std::endl;
   std::cout << "len2: " << lengthOfLongestSubstring2("##b") << std::endl;
   std::cout << "len3: " << lengthOfLongestSubstring2("wpwwef") << std::endl;
   std::cout << "len4: " << lengthOfLongestSubstring2("$$$$$") << std::endl;
   std::cout << "len5: " << lengthOfLongestSubstring2("abcabcbf") << std::endl;
*/

int lengthOfLongestSubstring(std::string s) {
    int maxLength = 0;
    int length = 0;
    std::unordered_set<int> traversedHash;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i; j < s.length(); ++j) {
            if (traversedHash.count(s[j])) {
                if (length > maxLength) {
                    maxLength = length;
                }
                length = 0;
                traversedHash.clear();
                break;
            } else {
                ++length;
                traversedHash.insert(s[j]);
            }
        }
    }

    return maxLength > length ? maxLength : length;
}

int lengthOfLongestSubstring2(std::string s) {
    std::vector<int> pos(256, -1);

    int basePos = 0;
    int maxLength = -1;
    for (int i = 0; i < s.length(); i++) {
        if (pos[s[i]] < basePos) {
            pos[s[i]] = i;
        } else {
            if (maxLength == -1 || i - basePos > maxLength) {
                maxLength = i - basePos;
            }

            basePos = pos[s[i]] + 1;
            pos[s[i]] = i;
        }
    }

    if (s.length() - basePos > maxLength || maxLength == -1) {
        maxLength = s.length() - basePos;
    }

    return maxLength;
}

