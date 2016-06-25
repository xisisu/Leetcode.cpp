//
// Created by xisisu on 6/25/16.
//

/*
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent
 * number in the sequence must be the sum of the preceding two.
 *
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 *
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 */

#include <iostream>
#include <vector>

class Solution {
private:
    bool helper(unsigned long first, unsigned long second, std::string const& num, int start) {
        if (start >= num.size())  { return false; }
        unsigned long const sum = first + second;
        std::string const sumStr = std::to_string(sum);
        if (num.substr(start, sumStr.size()).compare(sumStr) == 0) {
            if (start + sumStr.size() == num.size()) { return true; }
            else { return helper(second, sum, num, start+sumStr.size()); }
        } else {
            return false;
        }
    }

public:
    bool isAdditiveNumber(std::string const& num) { // 0 ms
        if (num.size() < 3) { return false; }
        for (int i = 1; i <= num.size()/2; ++i) { // len of first number
            for (int j = 1; i+j <= num.size()*2/3; ++j) { // len of second number
                // both numbers cannot start with 0, unless they are 0
                if (num.at(0) == '0' && i > 1) { continue; }
                if (num.at(i) == '0' && j > 1) { continue; }

                // [0,i] is first number, while [i, j] is second number
                long const first  = std::stol(num.substr(0, i));
                long const second = std::stol(num.substr(i, j));

                if (helper(first, second, num, i+j)) { return true; }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "123"
//            , "11"
//            , "110"
//            , "001"
//            , "101"
//            , "011"
//            , "000"
//            , "123"
//            , "1023"
//            , "112358"
//            , "11235813"
//            , "11235814"
//            , "199100199"
//            , "101111212"
//            , "198019823962"
    };

    for (auto const& test : tests) {
        std::cout << test << ", " << sol.isAdditiveNumber(test) << std::endl;
    }

    return 0;
}