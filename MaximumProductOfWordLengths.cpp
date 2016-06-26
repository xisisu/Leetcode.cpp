//
// Created by xisisu on 6/26/16.
//

/*
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not
 * share common letters. You may assume that each word will contain only lower case letters. If no such two words
 * exist, return 0.
 *
 * Example 1:
 * Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * Return 16
 * The two words can be "abcw", "xtfn".
 *
 * Example 2:
 * Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * Return 4
 * The two words can be "ab", "cd".
 *
 * Example 3:
 * Given ["a", "aa", "aaa", "aaaa"]
 * Return 0
 * No such pair of words.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int maxProduct(std::vector<std::string> const& words) { // 140 ms
        /*
         * naive solution, using bit mask
         */
        std::vector<int32_t> bit(words.size(), 0);

        int idx = 0;
        for (auto const& w : words) {
            for (auto const& c: w) {
                bit[idx] |= (1 << (c-'a'));
            }
            ++idx;
        }

        int res = 0;
        for (int i = 0; i < bit.size(); ++i) {
            for (int j = i+1; j < bit.size(); ++j) {
                if (bit[i] & bit[j]) { continue; }
                res = std::max(res, int(words[i].size() * words[j].size()));
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            {""}
            , {"a", "aa", "aaa", "aaaa"}
            , {"a", "ab", "abc", "d", "cd", "bcd", "abcd"}
            , {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << ": res: " << sol.maxProduct(test) << std::endl;
    }

    return 0;
}

