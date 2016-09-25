//
// Created by xisisu on 9/24/16.
//

/*
 * Given a string s and a string t, check if s is subsequence of t.
 *
 * You may assume that there is only lower case English letters in both s and t. t is potentially a very long
 * (length ~= 500,000) string, and s is a short string (<=100).
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none)
 * of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 * Example 1:
 * s = "abc", t = "ahbgdc"
 *
 * Return true.
 *
 * Example 2:
 * s = "axc", t = "ahbgdc"
 *
 * Return false.
 *
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T
 * has its subsequence. In this scenario, how would you change your code?
 */

#include <iostream>
#include <vector>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) { // 76 ms
        /*
         * if called many times, can build a hashMapCount to do it
         * can reduce t to a relative hashMap
         */
        int idx = 0;
        for (auto c : s) {
            while (idx < t.size() && t[idx] != c) { ++idx; }
            ++idx;
            if (idx > t.size()) { return false; }
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::string const t = "ahbgdc";
    std::vector<std::string> tests = {
            "abc"
            , "a"
            , "leetcode"
    };

    for (auto const& test : tests) {
        std::cout << test << ", " << sol.isSubsequence(test, t) << std::endl;
    }

    return 0;
}


