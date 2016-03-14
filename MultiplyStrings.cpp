//
// Created by Sisu on 3/13/2016.
//

/*
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

#include <iostream>
#include <vector>
#include <string>
#include "Common.h" // to_string

class Solution {
private:
    int getVal(std::string& num, int pos) {
        if (pos < 0 || pos >= num.size()) { return 0; }
        else { return num[pos] - '0'; }
    }

    std::string addTwoString(std::string& num1, std::string num2) {
        std::string res = "";
        int carry = 0;
        for (int i = 0; i < std::max(num1.size(), num2.size()); ++i) {
            int cur = getVal(num1, num1.size()-i-1) + getVal(num2, num2.size()-i-1);
            cur += carry;
            carry = cur / 10;
            res = to_string(cur % 10) + res;
        }
        if (carry) { res = to_string(carry) + res; }

        return res;
    }

    std::string multiplyByChar(std::string& nums, char c) {
        if (c == '0') { return "0"; }
        int factor = c - '0';

        int carry = 0;
        std::string res = "";
        for (int i = nums.size()-1; i >= 0; --i) {
            int cur = (nums.at(i)-'0') * factor;
            cur += carry;
            carry = cur / 10;
            res = to_string(cur%10) + res;
        }
        if (carry != 0) { res = to_string(carry) + res; }

        return res;
    }

public:
    std::string multiply(std::string num1, std::string num2) {
        std::string res = "0";

        for (int i = num2.size()-1; i >= 0; --i) {
            std::string cur = multiplyByChar(num1, num2[i]);
            for (int j = num2.size()-1-i; j > 0; --j) { cur = cur + "0"; } // shift left by i
            res = addTwoString(res, cur);
        }

        return res;
    }

    std::string multiply2(std::string num1, std::string num2) { // 8 ms
        /*
         * res[i+j] += num1[i] * num2[j], with some carry operations
         * init res to size 1+num1.size()+num2.size to prevent any carry over issue
         */
        std::vector<int> res(1 + num1.size() + num2.size(), 0);

        for (int i = 0; i < num1.size(); ++i) {
            auto a = getVal(num1, num1.size()-1-i);
            for (int j = 0; j < num2.size(); ++j) {
                auto b = getVal(num2, num2.size()-1-j);
                res[i+j] += a * b;
            }
        }

        // now calculate any carry part
        // since res is size 1+num1.size()+num2.size(), we do not need to worry about the last digit
        int carry = 0;
        for (int i = 0; i < res.size(); ++i) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }

        int start = res.size()-1;
        while (res[start] == 0 && start >= 0) { --start; }
        if (start < 0) { return "0"; }

        std::string s = "";
        while (start >= 0) { s.push_back('0' + res[start--]); }
        return s;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::string, std::string>> tests = {
            { "1", "1" }
            , { "1", "10" }
            , { "25", "25" }
            , { "52", "0" }
            , { "1234456798189", "0" }
            , { "12345678987654321", "12345678987654321"}
    };

    for (auto const& test : tests) {
        std::cout << test.first << " * " << test.second << " = " << sol.multiply(test.first, test.second) << ", "
                  << sol.multiply2(test.first, test.second) << std::endl;
    }

    return 0;
}