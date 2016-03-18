//
// Created by Sisu on 3/17/2016.
//

/*
 * Given an array of strings, group anagrams together.
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 * For the return value, each inner list's elements must follow the lexicographic order.
 * All inputs will be in lower-case.
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) { // 92 ms
        std::sort(strs.begin(), strs.end());
        std::map<std::string, std::vector<std::string>> map;
        for (auto const& str : strs) {
            std::string tmp = str;
            std::sort(tmp.begin(), tmp.end());
            map[tmp].push_back(str);
        }

        std::vector<std::vector<std::string>> res;
        for (auto const& val : map) {
            res.push_back(val.second);
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            {}
            , { "" }
            , { "eat", "tea", "tan", "ate", "nat", "bat"}
    };

    for (auto& test : tests)  {
        std::cout << std::endl << "input: ";
        for (auto v : test) { std::cout << v << ", "; }
        auto res = sol.groupAnagrams(test);
        std::cout << std::endl << "res:" << std::endl;
        for (auto const& val : res) {
            for (auto v : val) { std::cout << v << ", "; }
            std::cout << std::endl;
        }
    }

    return 0;
}