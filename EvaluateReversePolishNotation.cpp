//
// Created by Sisu on 4/9/2016.
//

/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <sstream>

class Solution {
private:
    bool isOperator(std::string const& t) {
        return t == "+" || t == "-" || t == "*" || t == "/";
    }

private:
    int calculate(int val1, int val2, std::string const& t) {
        if (t == "+") { return val1 + val2; }
        if (t == "-") { return val1 - val2; }
        if (t == "*") { return val1 * val2; }
        if (t == "/") { return val1 / val2; }
        return INT32_MIN;
    }

public:
    int evalRPN(std::vector<std::string> const& tokens) { // 20 ms
        /*
         * if empty vector, return 0
         * if invalid input, return INT_MIN
         */
        if (tokens.empty()) { return 0; }
        std::stack<int> s;
        for (auto const& t : tokens) {
            if (isOperator(t)) {
                if (s.size() < 2) { return INT32_MIN; }
                auto val2 = s.top(); s.pop();
                auto val1 = s.top(); s.pop();
                auto val3 = calculate(val1, val2, t);
                s.push(val3);
            } else {
                s.push(atoi(t.c_str()));
            }
        }

        if (s.size() != 1) { return INT32_MIN; }
        return s.top();
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            { }
//            , { "2", "1", "+" }
//            , { "2", "1", "-" }
//            , { "2", "1", "*" }
            , { "2", "1", "/" }
            , { "2", "1", "+", "3", "*" }
            , { "4", "13", "5", "/", "+" }
            , { "1", "2" } // invalid input
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "result: " << sol.evalRPN(test) << std::endl << std::endl;
    }

    return 0;
}

