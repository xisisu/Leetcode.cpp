//
// Created by Sisu on 11/10/2015.
//

/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> res;
    std::vector<std::string> generateParenthesis(int n) { // 4 ms
        res.clear();
        helper("", 0, 0, n);
        return res;
    }

    void helper(std::string cur, int left, int right, int n) {
        if (n == 0 || right > left || left > n || right > n) { return; } // invalid case
        if (left == n && right == n) { // found it!
            res.push_back(cur);
        } else {
            helper(cur+"(", left+1, right, n);
            helper(cur+")", left, right+1, n);
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {0, 1, 2, 3};
    for (const auto& item : tests) {
        std::cout << item << ": ";
        for (const auto& val: sol.generateParenthesis(item)) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
