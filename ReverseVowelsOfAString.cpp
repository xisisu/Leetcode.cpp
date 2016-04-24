//
// Created by Sisu on 4/24/2016.
//

/*
 * Write a function that takes a string as input and reverse only the vowels of a string.
 *
 * Example 1:
 * Given s = "hello", return "holle".
 *
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 */

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
private:
    std::unordered_set<char> _vowels;

public:
    Solution() {
        _vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    }

public:
    std::string reverseVowels(std::string const& s) { // 32 ms
        if (s.size() < 2) { return s; }
        std::string res = s;
        int start = 0, end = s.size()-1;
        while (start < end) {
            while (!_vowels.count(s.at(start)) && start < end) { ++start; }
            if (start >= end) { return res; } // early quit to speed up
            while (!_vowels.count(s.at(end)) && start < end) { --end; }
            if (start < end) {
                std::swap(res[start], res[end]);
                ++start;
                --end;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "a"
            , "bcdfg"
            , "abcdfg"
            , "abcde"
            , "hello world"
            , "leetcode"
    };

    for (auto const& test : tests) {
        std::cout << test << ", " << sol.reverseVowels(test) << std::endl;
    }
    return 0;
}