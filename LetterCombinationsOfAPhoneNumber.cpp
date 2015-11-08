//
// Created by Sisu on 11/8/2015.
//

/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    std::map<char, std::vector<std::string>> map = { {'2', {"a", "b", "c"}},
                                                      {'3', {"d", "e", "f"}},
                                                      {'4', {"g", "h", "i"}},
                                                      {'5', {"j", "k", "l"}},
                                                      {'6', {"m", "n", "o"}},
                                                      {'7', {"p", "q", "r", "s"}},
                                                      {'8', {"t", "u", "v"}},
                                                      {'9', {"w", "x", "y", "z"}} };
    std::vector<std::string> letterCombinations(std::string digits) { // 0 ms
        std::vector<std::string> res;
        switch (digits.size()) {
            case 0: break;
            case 1: res = map[digits[0]]; break;
            default:
                auto tmp = letterCombinations(digits.substr(1, digits.size()-1));
                for (auto const c : map[digits[0]]) {
                    for (auto const item : tmp) {
                        res.push_back(c + item);
                    }
                }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"23"};
    for (auto item : tests) {
        for (auto val : sol.letterCombinations(item)) {
            std::cout << val << ",";
        }
        std::cout << std::endl;
    }
    return 0;
}