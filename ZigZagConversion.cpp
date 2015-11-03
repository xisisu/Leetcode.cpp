//
// Created by Sisu on 11/1/2015.
//

/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to
 * display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>

class Solution {
public:
    std::string convert(std::string s, int numRows) { // 16 ms
        int n = s.size();
        if (n <= numRows || numRows < 2) { return s; }
        char res[n];
        int idx = 0;
        for (int row = 0; row < numRows; ++row) {
            auto total = 2 * numRows - 2;
            if (0 == row || numRows-1 == row) {
                for (int start = row; start < n; start += total) {
                    res[idx++] = s[start];
                }
            } else {
                int len1 = total - row*2, len2 = row*2;
                auto start = row;
                while (start < n) {
                    res[idx++] = s[start];
                    if (start+len1 < n) {
                        start += len1;
                        res[idx++] = s[start];
                        start += len2;
                    } else {
                        break;
                    }
                }
            }
        }
        std::string tmp(n, '\n');
        memcpy(&tmp[0], res, n);
        return std::string(res);
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"PAYPALISHIRING", "ABC"};
    for (auto item : tests) {
        auto res = sol.convert(item, 2);
        std::cout << res.size() << " " << res << std::endl;
    }
    return 0;
}