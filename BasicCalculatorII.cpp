//
// Created by xisisu on 6/8/16.
//

/*
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer
 * division should truncate toward zero.
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 * Note: Do not use the eval built-in library function.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>

class Solution {
private:
    constexpr static int NON_VAL = INT32_MIN;
    constexpr static char NON_OP = '#';
    std::unordered_set<char> validOps = {'+', '-', '*', '/'};

private:
    int getVal(std::string const& s, int& pos) {
        int res = 0;
        pos = s.find_first_not_of(" ", pos); // skip all spaces
        if (pos == std::string::npos) { return NON_VAL; }
        while (pos < s.size() && s.at(pos) >= '0' && s.at(pos) <= '9') {
            res *= 10;
            res += (s.at(pos) - '0');
            ++pos;
        }
        return res;
    }

private:
    char getOps(std::string const& s, int& pos) {
        pos = s.find_first_not_of(" ", pos); // skip all spaces
        if (pos == std::string::npos) { return NON_OP; }
        auto res = s.at(pos++);
        return validOps.count(res) ? res : NON_OP;
    }


public:
    int calculate(std::string const& s) { // 44 ms
        if (s.empty() || s.find_first_not_of(" ") == std::string::npos) { return 0; }
        /*
         * since we only have +*-/ four operations, we follow the rules below
         * whenver we see * or /, performs the operation
         * if we see -, just push negative number to stack
         * if we see +, just push the number to stack
         *
         * sume the stack up and get the results.
         */

        std::stack<int> nums;
        int pos = 0;
        nums.push(getVal(s, pos));
        while (pos < s.size() && s.find_first_not_of(" ", pos) != std::string::npos) {
            auto const nextOp  = getOps(s, pos);
            auto nextNum = getVal(s, pos);
            auto curNum  = nums.top();
            switch (nextOp) {
                case '*': nextNum = curNum * nextNum; nums.pop(); break;
                case '/': nextNum = curNum / nextNum; nums.pop(); break;
                case '-': nextNum = -nextNum; break;
                case '+': break;
            }
            nums.push(nextNum);
        }

        int res = 0;
        while (!nums.empty()) { res += nums.top(); nums.pop(); }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            "    "
            , ""
            , "0"
            , "     1"
            , "2    "
            , "  3   "
            , "1+   2"
            , "3+2*2"
            , "3/2 "
            , " 3+5 /2 "
            , "1+1-1"
    };

    for (auto const& test : tests) {
        std::cout << test << " = " << sol.calculate(test) << std::endl;
    }

    return 0;
}