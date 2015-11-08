//
// Created by Sisu on 11/8/2015.
//

/*
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

/*
 * Roman numbers: I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
 */

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) { // 36 ms
        std::string res;
        if (num <= 0 || num >= 4000) { return res; }
        res += healper(num / 1000, 'M', ' ', ' '); num %= 1000;
        res += healper(num / 100,  'C', 'D', 'M'); num %= 100;
        res += healper(num / 10,   'X', 'L', 'C'); num %= 10;
        res += healper(num,        'I', 'V', 'X');
        return res;
    }

    std::string healper(int digit, char single, char five, char ten) {
        std::string res;
        if (digit == 0) {           //  0
            ;  // nothing is needed here
        } else if (digit <= 3) {   // 1, 2, 3
            while (digit-- > 0) { res += single; }
        } else if (digit == 4) {  // 4
            res += single; res += five;
        } else if (digit <= 8) {  // 5, 6, 7, 8
            res += five;
            while (digit-- > 5) { res += single; }
        } else if (digit == 9) {  // 9
            res += single; res += ten;
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {0, 10, 50, 60, 80, 100, 3999};
    for (auto item : tests) {
        std::cout << item << ", " << sol.intToRoman(item) << std::endl;
    }
    return 0;
}

