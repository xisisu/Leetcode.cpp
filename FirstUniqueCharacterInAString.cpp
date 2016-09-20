//
// Created by xisisu on 9/19/16.
//

/*
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 * Note: You may assume the string contain only lowercase letters.
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int firstUniqChar(std::string s) { // 45 ms
        // since stirngs are all lower case, use a 26 size array to store the map
        if (s.empty()) { return -1; }
        int hashtable[26];
        for (int i = 0; i < 26; ++i) { hashtable[i] = 0; }
        for (auto const c : s) { ++hashtable[c-'a']; }
        for (int i = 0; i < s.size(); ++i) {
            if (hashtable[s[i]-'a'] == 1) { return i; }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "abcd"
            , "leetcode"
            , "abcdabcd"
            , "abcdabc"
            , "itwqbtcdprfsuprkrjkausiterybzncbmdvkgljxuekizvaivszowqtmrttiihervpncztuoljftlxybpgwnjb"
    };

    for (auto const test : tests) {
        std::cout << test << ": " << sol.firstUniqChar(test) << std::endl;
    }

    return 0;
}


