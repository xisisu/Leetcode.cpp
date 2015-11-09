//
// Created by Sisu on 11/8/2015.
//

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
 * valid
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>

class Solution {
public:
    bool isValid(std::string s) { // 0 ms
        std::stack<char> stack;
        for (auto c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    stack.push(c);
                    break;
                case ')':
                    if (stack.empty() || stack.top() != '(') { return false; }
                    stack.pop();
                    break;
                case ']':
                    if (stack.empty() || stack.top() != '[') { return false; }
                    stack.pop();
                    break;
                case '}':
                    if (stack.empty() || stack.top() != '{') { return false; }
                    stack.pop();
                    break;
                default:
                    return false;
            }
        }
        return stack.empty();
    }

    bool isValid_2(std::string s) { // 0 ms
        const std::map<char, char> map = { {')', '('}, {']', '['}, {'}', '{'} };
        const std::set<char> set = { '(', '[', '{', ')', ']', '}' };
        std::stack<char> stack;
        for (auto c : s) {
            if (!set.count(c)) { return false; }
            else if (!map.count(c)) { stack.push(c); }
            else {
                if (!stack.empty() && stack.top() == map.at(c)) { stack.pop(); }
                else { return false; }
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"()[]{}", "((([[[]]])))", "(["};
    for (auto item : tests) {
        std::cout << item << "," << sol.isValid(item) << std::endl;
    }
    return 0;
}