//
// Created by Sisu on 11/22/2015.
//

/*
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * For example:
 *  A -> 1
 *  B -> 2
 *  C -> 3
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int titleToNumber(std::string s) { // 8 ms
        int res = 0;
        for (const auto & item : s) {
            res *= 26;
            res += item-'A'+1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"AB", "A"};
    for (const auto & item : tests) {
        std::cout << item << ", " << sol.titleToNumber(item) << std::endl;
    }
    return 0;
}