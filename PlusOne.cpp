//
// Created by Sisu on 11/28/2015.
//

/*
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) { // 4 ms
        int carry = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            if (carry == 0) { return digits; }
            auto val = carry + digits[i];
            digits[i] = val % 10;
            carry = val / 10;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {9,9,9,9,9};
    for (const auto item : sol.plusOne(tests)) {
        std::cout << item;
    }
    std::cout << std::endl;
    return 0;
}