//
// Created by Sisu on 4/20/2016.
//

/*
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of
 * one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    bool wordBreak(std::string const& s, std::unordered_set<std::string> const& wordDict) { // time exceed
        if (s.empty() || wordDict.count(s)) { return true; }
        if (wordDict.empty()) { return false; }

        for (int i = 1; i < s.size(); ++i) {
            auto left  = s.substr(0, i);
            auto right = s.substr(i);
            if (wordDict.count(right) && wordBreak(left, wordDict)) { return true; }
        }

        return false;
    }

    bool wordBreak2(std::string const& s, std::unordered_set<std::string> const& wordDict) { // 16 ms
        if (s.empty() || wordDict.count(s)) { return true; }
        if (wordDict.empty()) { return false; }

        std::vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDict.count(s.substr(j, i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    Solution sol;
    std::unordered_set<std::string> dict = {"leet", "code", "word", "break"};
    std::vector<std::string> tests = {
            "leetcode"
            , "wordbreak"
            , "word break"
    };

    for (auto const& test : tests) {
        std::cout << test << ", " << sol.wordBreak(test, dict) << std::endl;
    }

    return 0;
}