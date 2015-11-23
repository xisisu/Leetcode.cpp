//
// Created by Sisu on 11/22/2015.
//

/*
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include <iostream>
#include <vector>
#include <string.h>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) { // 12 ms
        if (s.size() != t.size()) { return false; }

        int table[256];
        memset(table, 0, sizeof(table));

        for (int i = 0; i < s.size(); ++i) { table[s[i]]++; }
        for (int i = 0; i < t.size(); ++i) {
            if (--table[t[i]] < 0) { return false; }
        }

        return true;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isAnagram("1234", "4321") << std::endl;
    std::cout << sol.isAnagram("asdf", "asdf") << std::endl;
    std::cout << sol.isAnagram("12354", "asdjklh") << std::endl;

    return 0;
}