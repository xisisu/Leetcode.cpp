//
// Created by Sisu on 12/3/2015.
//

/*
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * All occurrences of a character must be replaced with another character while preserving the order of characters.
 * No two characters may map to the same character but a character may map to itself.
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 * Note:
 * You may assume both s and t have the same length.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) { // 8 ms
        char sToT[256]; memset(sToT, 0, sizeof sToT);
        char tToS[256]; memset(tToS, 0, sizeof tToS);
        for (int i = 0; i < s.size(); ++i) {
            if (sToT[s[i]] == 0) { sToT[s[i]] = t[i]; }
            else { if (sToT[s[i]] != t[i]) { return false; } }
            if (tToS[t[i]] == 0) { tToS[t[i]] = s[i]; }
            else { if (tToS[t[i]] != s[i]) { return false; } }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isIsomorphic("ab", "aa") << std::endl;
    return 0;
}

