//
// Created by Sisu on 11/1/2015.
//

/*
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest
 * substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 * For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <string.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) { // 64 ms
        std::set<char> set;
        int start = 0;
        int res = 0, cur = 0;
        for (int idx = 0; idx < s.size(); ++idx) {
            if (set.count(s[idx])) {
                res = std::max(res, cur); // get the max val
                while (start < idx) {
                    if (s[start] == s[idx]) { // found it
                        // no need to modify the set, as it is already moved
                        // no need to --cur, as it is already the current val
                        // but do need to ++start
                        ++start;
                        break;
                    }
                    set.erase(s[start]);
                    ++start;
                    --cur;
                }
            } else {
                set.insert(s[idx]);
                ++cur;
            }
        }
        res = std::max(res, cur);
        return res;
    }

    // dynamic programming
    int lengthOfLongestSubstring_2(std::string s) { // 16 ms
        if (s == "") { return 0; }
        int last_appearance[256];
        memset(last_appearance, -1, sizeof(last_appearance));
        last_appearance[s[0]] = 0;
        int cur = 1, res = 1;
        for (int idx = 1; idx < s.size(); ++idx) {
            if (last_appearance[s[idx]] == -1) {
                ++cur;
            } else {
                cur = std::min(cur+1, idx-last_appearance[s[idx]]);
            }
            last_appearance[s[idx]] = idx;
            res = std::max(res, cur);
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::string input = "tmmzuxt";
    auto res = sol.lengthOfLongestSubstring_2(input);
    std::cout << res << std::endl;

    return 0;
}