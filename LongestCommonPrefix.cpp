//
// Created by Sisu on 11/8/2015.
//

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) { return ""; }
        auto res = strs[0];
        for (auto i = 1; i < strs.size(); ++i) {
            if (res.size() == 0) { break; }
            if (res.size() > strs[i].size()) { res.resize(strs[i].size()); }
            for (auto j = 0; j < res.size(); ++j) {
                if (res[j] != strs[i][j]) {
                    res.resize(j);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"a", "b"};
    std::cout << sol.longestCommonPrefix(tests) << std::endl;
    return 0;
}