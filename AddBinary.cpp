//
// Created by Sisu on 11/28/2015.
//

/*
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int valueAt(std::string a, int idx) {
        if (idx >= a.size() || idx < 0) { return 0;}
        return a[idx] - '0';
    }

    std::string addBinary(std::string a, std::string b) { // 4 ms
        if (a.empty()) { return b; }
        if (b.empty()) { return a; }

        int carry = 0;
        std::string c = "";
        for (int idx = 0; idx < std::max(a.size(), b.size()); ++idx) {
            int val = valueAt(a, a.size()-1-idx) + valueAt(b, b.size()-1-idx) + carry;
            carry = val / 2;
            c.append(1, '0' + val % 2);
        }
        if (carry) { c.append("1"); }
        std::reverse(c.begin(), c.end());

        return c;
    }
};

int main() {
    Solution sol;
    std::string a = "11", b = "1";
    auto c = sol.addBinary(a, b);
    std::cout << c << std::endl;
    return 0;
}