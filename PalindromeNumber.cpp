//
// Created by Sisu on 11/3/2015.
//

/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 * Could negative integers be palindromes? (ie, -1)
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
 * you know that the reversed integer might overflow. How would you handle such case?
 * There is a more generic way of solving this problem.
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
    bool isPalindrome(int x) { // 96 ms
        if (x < 0) { return false; }
        int res = 0, tmp = x;
        while (tmp != 0) {
            res *= 10;
            res += tmp % 10;
            tmp /= 10;
        }
        return res == x;
    }

    bool isPalindrome_2(int x) { // 84 ms
        if (x == 0) { return true; }
        else if (x < 0 || x % 10 == 0) { return false; }
        int y = 0;
        while (y <= x) {
            if (x == y) { return true; }
            y *= 10; y += x % 10;
            if (x == y) { return true; }
            x /= 10;
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {10, 11, 1234321, 1000000001, 1000021, 1, -1, 10, -10,121,123321, 12345};
    for (auto item : tests) {
        auto res = sol.isPalindrome_2(item);
        std::cout << item << "," << res << std::endl;
    }
    return 0;
}