//
// Created by xisisu on 6/17/16.
//

/*
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8,
 *  9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 * Hint:
 *
 * The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly.
 *  Try to focus your effort on generating only the ugly ones.
 * An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
 * The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted
 *  lists: L1, L2, and L3.
 * Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
 */

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
private:
    bool isUgly(int n) {
        while (n%2 == 0) { n /= 2; }
        while (n%3 == 0) { n /= 3; }
        while (n%5 == 0) { n /= 5; }
        return n == 1;
    }

public:
    int nthUglyNumber(int n) { // time limit exceed at 500
        if (n <= 0) { return 0; }
        int cur = 0;
        while (n > 0) {
            ++cur;
            while (!isUgly(cur)) { ++cur; }
            --n;
        }
        return cur;
    }

private:
    std::unordered_set<int> _uglyNumber;

private:
    bool isUgly2(int n){
        return n == 1 ||
                (n%2 == 0 && _uglyNumber.count(n/2)) ||
                (n%3 == 0 && _uglyNumber.count(n/3)) ||
                (n%5 == 0 && _uglyNumber.count(n/5));
    }

public:
    int nthUglyNumber2(int n) { // time limit exceed on 357
        if (n <= 0) { return 0; }
        int cur = 0;
        while (n > 0) {
            ++cur;
            while (!isUgly2(cur)) { ++cur; }
            _uglyNumber.insert(cur);
            --n;
        }
        return cur;
    }

public:
    int nthUglyNumber3(int n) { // 20 ms
        if (n <= 0) { return 0; }
        if (n == 1) { return 1; }
        int c2 = 1, c3 = 1, c5 = 1;
        std::vector<int> number = {0, 1};
        while (n > 1) {
            int cur = std::min(number[c5]*5, std::min(number[c3]*3, number[c2]*2));
            number.push_back(cur);
            // run all of them to skip duplicate
            if (number[c5] * 5 == cur) { ++c5; }
            if (number[c3] * 3 == cur) { ++c3; }
            if (number[c2] * 2 == cur) { ++c2; }
            --n;
        }

        return number.back();
    }
};

int main() {
    Solution sol;
    for (int i = 1; i <= 10; ++i) {
        std::cout << i << ", " << sol.nthUglyNumber3(i) << std::endl;
    }
    return 0;
}