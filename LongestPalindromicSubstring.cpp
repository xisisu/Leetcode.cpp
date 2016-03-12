//
// Created by Sisu on 11/8/2015.
//

/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 */

#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    std::string helper(std::string const&str, int s, int e) {
        while (s >= 0 && e < str.size() && str[s] == str[e]) {
            --s; ++e;
        }
        return str.substr(s+1, e-s-1);
    }

public:
    std::string longestPalindrome(std::string const&s) { // 64 ms
        if (s.size() < 2) { return s; }

        std::string res = "";
        for (int i = 0; i < s.size()-1; ++i) {
            // treat i as the center, for example, aba
            std::string s1 = helper(s, i, i);

            // treat i,i+1 as the center, for example, abba
            std::string s2 = helper(s, i, i+1);

            if (s1.size() > res.size()) { res = s1; }
            if (s2.size() > res.size()) { res = s2; }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""                  // empty
            , "a"               // single digit
            , "abcdefg"        // str with diff characters
            , "qwerabacdefg"  // "aba"
            , "abaaba"         // "abaaba"
            , "abawqernbabba" // "abba"
    };

    for (auto const& test: tests) {
        std::cout << "(" << test << ", " << sol.longestPalindrome(test) << ")" << std::endl;
    }

    return 0;
}