//
// Created by Sisu on 4/24/2016.
//

/*
 * Write a function that takes a string as input and returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string reverseString(std::string const& s) { // 20 ms
        auto res = s;
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::string reverseString2(std::string const& s) { // 264 ms
        std::string res = "";
        for (auto c : s) {
            res.insert(res.begin(), c);
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "a"
            , "abc"
            , "a b c"
    };

    for(auto const& test : tests) {
        std::cout << test << ", " << sol.reverseString2(test) << std::endl;
    }
    return 0;
}