//
// Created by Sisu on 11/22/2015.
//

/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
 * parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int longestValidParentheses(std::string s) { // 12 ms
        int res = 0, start = 0;
        std::stack<int> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') { stack.push(i); }
            else if (stack.empty()) { start = i + 1; }
            else {
                stack.pop();
                auto len = stack.empty() ? i-start+1 : i-stack.top();
                res = std::max(res, len);
            }
        }
        return res;
    }

    // dynamic programming
    int longestValidParentheses_2(std::string s) { // 8 ms
        std::vector<int> table(s.size(), 0);
        int res = 0;
        for (int i = s.size()-2; i >= 0; --i) {
            int match = i + table[i+1] + 1;
            if (s[i] == '(' && match < s.size() && s[match] == ')') {
                table[i] = table[i+1] + 2; // case '((...))'
                if (match + 1 < s.size()) table[i] += table[match+1]; // case '()()'
            }
            res = std::max(res, table[i]);
        }
        return res;
    }

    // scan twice
    int longestValidParentheses_3(std::string s) { // 8 ms
        int res = 0;

        // scan from left to right, note this is not enough, for example, '(()'
        int depth = 0, start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') { ++depth; }
            else {
                --depth;
                if (depth < 0) {
                    start = i; depth = 0;
                } else if (depth == 0) {
                    res = std::max(res, i - start);
                }
            }
        }

        // scan from right to left, same algorithm
        depth = 0, start = s.size();
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == ')') { ++depth; }
            else {
                --depth;
                if (depth < 0) {
                    start = i; depth = 0;
                } else if (depth == 0) {
                    res = std::max(res, start - i);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"(()", "()()()()()()())", "(((((()((((((((((()(((((((((()"};
    for (const auto & item : tests) {
        std::cout << item << ", " << sol.longestValidParentheses_3(item) << std::endl;
    }
    return 0;
}