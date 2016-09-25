//
// Created by xisisu on 9/24/16.
//

/*
 * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is
 * the smallest possible.
 *
 * Note:
 * The length of num is less than 10002 and will be ≥ k.
 * The given num does not contain any leading zero.
 * Example 1:
 *
 * Input: num = "1432219", k = 3
 * Output: "1219"
 * Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 * Example 2:
 *
 * Input: num = "10200", k = 1
 * Output: "200"
 * Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 * Example 3:
 *
 * Input: num = "10", k = 2
 * Output: "0"
 * Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */

#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) { // 3 ms
        if (k >= num.size()) { return "0"; }
        std::string res;
        for (auto c : num) {
            while (res.size() != 0 && k > 0 && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }

        while (k-- != 0) { res.pop_back(); }

        if (res.find_first_not_of("0") == std::string::npos) { return "0"; }
        return res.substr(res.find_first_not_of("0"));
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::string, int>> tests = {
            { "000000", 1 }
            , { "1234567890", 1 }
            , { "9876543210", 1 }
    };

    for (auto test : tests) {
        std::cout << test.first << ", " << test.second << ": " << sol.removeKdigits(test.first, test.second) << std::endl;
    }

    return 0;
}