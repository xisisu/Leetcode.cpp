//
// Created by xisisu on 6/12/16.
//

/*
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways
 *  to group numbers and operators. The valid operators are +, - and *.
 *
 *
 * Example 1
 * Input: "2-1-1".
 *
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 *
 *
 * Example 2
 * Input: "2*3-4*5"
 *
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10]
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <unordered_map>;

class Solution {
private:
    std::unordered_set<char> _validOps = {'+', '-', '*'};

public:
    std::vector<int> diffWaysToCompute(std::string const& input) { // 4 ms
        if (input.empty()) { return {}; }
        if (_map.count(input)) { return _map[input]; }
        std::vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            auto const c = input.at(i);
            if (_validOps.count(c)) {
                auto res1 = diffWaysToCompute(input.substr(0, i));
                auto res2 = diffWaysToCompute(input.substr(i+1));
                for (auto const& val1 : res1) {
                    for (auto const& val2 : res2) {
                        switch (c) {
                            case '+' : res.push_back(val1 + val2); break;
                            case '-' : res.push_back(val1 - val2); break;
                            case '*' : res.push_back(val1 * val2); break;
                        }
                    }
                }
            }
        }
        if (res.empty()) { res.push_back(std::stoi(input.c_str())); }
        _map[input] = res;
        return res;
    }

private:
    std::unordered_map<std::string, std::vector<int>> _map;
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            "2-1-1"
            , "2*3-4*5"
    };

    for (auto const& test : tests) {
        std::cout << test << ", ";
        auto res = sol.diffWaysToCompute(test);
        for (auto const& val : res) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}