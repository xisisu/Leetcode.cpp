//
// Created by Sisu on 4/2/2016.
//

/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 * For example:
 * Given "25525511135",
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include <iostream>
#include <vector>
#include <stdlib.h>

class Solution {
private:
    void helper(std::string const& s, std::vector<std::string>& res, int idx, std::string cur, int n) {
        if (idx > s.size() || n > 4) { return; }
        if (idx == s.size() && n == 4) { res.push_back(cur); return; }

        for (int len = 1; len <= 3; ++len) {
            if (idx + len > s.size()) { break; }

            auto substr = s.substr(idx, len);
            auto val = atoi(substr.c_str());
            if (val > 255) { break; }

            auto tmp = cur;
            if (!tmp.empty()) { tmp.append(".", 1); }
            tmp.append(substr.c_str(), substr.size());
            helper(s, res, idx+len,tmp, n+1);

            if (val == 0) { break; } // corner case! consider val is 0
        }
    }

public:
    std::vector<std::string> restoreIpAddresses(std::string const& s) { // 4 ms
        std::vector<std::string> res;
        helper(s, res, 0, "", 0);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            "1234"
            , "010010"
            , "25525511135"
            , "255255255255"
            , "111111"
    };

    for (auto const& test : tests) {
        auto res = sol.restoreIpAddresses(test);
        std::cout << "input: " << test << std::endl << "output: ";
        for (auto const& val : res) {
            std::cout << val << ", ";
        }
        std::cout << std::endl << std::endl;
    }

    return 0;
}