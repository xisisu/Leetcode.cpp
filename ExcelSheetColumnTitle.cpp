//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * For example:
 *  1 -> A
 *  2 -> B
 *  3 -> C
 *  ...
 *  26 -> Z
 *  27 -> AA
 *  28 -> AB
 */

#include <iostream>
#include <string>

class Solution {
public:
    std::string convertToTitle(int n) { // 0 ms
        std::string res = "";
        while (n) {
            char c = n%26 == 0 ? 'Z' : (n%26) - 1 + 'A';
            n = (n-1) / 26;
            res = c + res;
        }
        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i < 100; ++i) {
        std::cout << i << ", " << sol.convertToTitle(i) << std::endl;
    }
    return 0;
}