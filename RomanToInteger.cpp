//
// Created by Sisu on 11/8/2015.
//

/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

/*
 * Roman numbers: I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    std::map<char, int> map = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int romanToInt(std::string s) { // 60 ms
        int res = 0;
        for (auto i = 0; i < s.size(); ++i) {
            if (i == s.size()-1) { res += map[s[i]]; }
            else {
                auto val = map[s[i+1]] / map[s[i]];
                if (val > 1 && val <= 10) { // this is a 4 or 9
                    res += map[s[i+1]]; res -= map[s[i]];
                    ++i; // advance 1 more here
                } else {
                    res += map[s[i]];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"III", "MMM", "DC", "CD"};
    for (auto item : tests) {
        std::cout << item << "," << sol.romanToInt(item) << std::endl;
    }
    return 0;
}