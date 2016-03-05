//
// Created by Sisu on 3/5/2016.
//

/*
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in
 * str.
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single
 * space.
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) { // 0 ms
        std::vector<std::string> words;
        std::istringstream iss(str);
        std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(),
                  std::back_inserter(words));

        if (pattern.size() != words.size()) { return false; }

        std::map<char, std::string> _map;
        std::set<std::string> _used;
        for (int i = 0; i < pattern.size(); ++i) {
            std::string word = words[i];
            char c = pattern.at(i);
            if (_map.find(c) != _map.end()) {
                if (_map[c] != word) { return false; }
            } else {
                _map[c] = word;
                if (_used.count(word)) { return false; }
                _used.insert(word);
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::string, std::string>> tests = {
            {"abba", "dog cat cat dog"}
            , {"abba", "dog cat cat fish"}
            , {"aaaa", "dog cat cat dog"}
            , {"abba", "dog dog dog dog"}
            , {"aaa", "aa aa aa aa"}
    };

    for (auto const& test : tests) {
        std::cout << "input: " << test.first << ", " << test.second << std::endl;
        std::cout << "result: " << sol.wordPattern(test.first, test.second) << std::endl;
    }

    return 0;
}