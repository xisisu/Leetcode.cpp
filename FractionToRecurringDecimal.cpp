//
// Created by Sisu on 4/30/2016.
//

/*
 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 * For example,
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * Hint:
 * No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
 * Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
 * Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include "Common.h"

class Solution {
private:
    long long findGcd(long long a, long long b) {
        // euclid's algorithm, see wiki page
        if (a > b) { std::swap(a, b); }
        if (a == 0) { return b; }
        return findGcd(a, b % a);
    }

public:
    std::string fractionToDecimal(int numerator, int denominator) { // 0 ms
        if (denominator == 0) { return "0"; } // invalid
        if (numerator == 0) { return "0"; }

        long long a = numerator, b = denominator; // use long to deal with INT32_MIN
        std::string res = "";

        // 0. decide the sign
        bool negative = false;
        if (a < 0) { a = -a; negative ^= true; }
        if (b < 0) { b = -b; negative ^= true; }
        if (negative) { res.push_back('-'); }

        // 1. reduce by greatest common factor
        auto gcd = findGcd(a, b);
        a /= gcd;
        b /= gcd;

        // 2. now the integer part
        res += to_string(a/b);
        a %= b;
        if (a == 0) { return res; }
        res.push_back('.');

        // 3. now the decimal part
        std::unordered_map<int, int> num2id; // from numerator to the first location, used for the '()'
        while (a != 0) {
            a *= 10;
            if (num2id.count(a)) { // found a repeating pattern, insert the '()'
                res.insert(res.begin() + num2id[a], '(');
                res.push_back(')');
                return res;
            }

            res.push_back('0' + a/b);
            num2id[a] = res.size()-1;

            a %= b;
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, int>> tests = {
            {0, 0}
            , {1, 2}
            , {2, 1}
            , {1, 1}
            , {2, 3}
            , {4, 9}
            , {4, 333}
            , {-1, -2}
            , {-1, 2}
            , {1, -2}
            , {10000, 1000}
            , {-1, -2147483648}
    };

    for (auto const& test : tests) {
        std::cout << test.first << " / " << test.second << " = " << sol.fractionToDecimal(test.first, test.second) << std::endl;
    }

    return 0;
}