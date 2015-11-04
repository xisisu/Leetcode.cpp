//
// Created by Sisu on 11/3/2015.
//

/*
 * Implement atoi to convert a string to an integer.
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and
 * ask yourself what are the possible input cases.
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 * You are responsible to gather all the input requirements up front.
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

class Solution {
public:
    int myAtoi(std::string str) { // 12 ms
        if (str.empty()) { return 0; }
        // get rid of heading and tailing space
        auto pos1 = str.find_first_not_of(' ');
        auto pos2 = str.find_last_not_of(' ');
        if (pos1 == std::string::npos) { pos1 = 0; }
        if (pos2 == std::string::npos) { pos2 = str.size(); }
        auto tmp = str.substr(pos1, std::min(str.size(), pos2-pos1+1));
        if (tmp.empty()) { return 0; }

        bool negative = false;
        int res = 0;
        if (tmp[0] >= '0' && tmp[0] <= '9') { res = tmp[0] - '0'; }
        else if (tmp[0] == '+') {}
        else if (tmp[0] == '-') { negative = true; }
        else { return 0; }

        for (auto i = 1; i < tmp.size(); ++i) {
            auto c = tmp[i];
            if (c < '0' || c > '9') { return res; }
            auto val = c - '0';
            if (!negative) {
                if ( (std::numeric_limits<int>::max()-val)/10 < res) { return std::numeric_limits<int>::max(); }
                res *= 10;
                res += val;
            } else {
                if ( (std::numeric_limits<int>::min()+val)/10 > res) { return std::numeric_limits<int>::min(); }
                res *= 10;
                res -= val;
            }
        }
        return res;
    }

    int myAtoi_2(std::string str) {
        if (str.empty()) { return 0; }

        // get rid of heading 0
        auto i = str.find_first_not_of(' ');
        if (i == str.size()) { return 0; }

        // deal with sign
        int sign = 1;
        if (str[i] == '-') { sign = -1; ++i; }
        else if (str[i] == '+') { ++i; }

        // use long long to convert to int
        long long res = 0;
        while (i < str.size()) {
            if (str[i] < '0' || str[i] > '9') { break; }
            res *= 10;
            res += str[i] - '0';
            if (sign*res > std::numeric_limits<int>::max()) { return std::numeric_limits<int>::max(); }
            else if (sign*res < std::numeric_limits<int>::min()) { return std::numeric_limits<int>::min(); }
            ++i;
        }

        return static_cast<int>(sign * res);
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"9223372036854775809", "-2147483649", "1a", "0", "123", "+123", "-123", "   123   ", "", "   ", "1a", "-1"};
    for (auto item : tests) {
        int res = sol.myAtoi_2(item);
        std::cout << item << ", " << res << std::endl;
    }
    return 0;
}