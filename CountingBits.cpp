//
// Created by xisisu on 6/26/16.
//

/*
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's
 * in their binary representation and return them as an array.
 *
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 *
 * Follow up:
 *
 * It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time
 * O(n) /possibly in a single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other
 * language.
 * Hint:
 *
 * You should make use of what you have produced already.
 * Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
 * Or does the odd/even status of the number help you in calculating the number of 1s?
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> countBits(int num) { // 100 ms
        std::vector<int> res(num+1, 0);
        int count = 1;
        for (int i = 0; std::pow(2, i) <= num; ++i) {
            for (int j = 0; j < std::pow(2, i); ++j) {
                res[count++] = res[j] + 1;
                if (count > num) { return res; }
            }
        }
        return res;
    }

public:
    std::vector<int> countBits2(int num) { // 104 ms
        std::vector<int> res(num+1, 0);
        if (num > 0) { res[1] = 1; }
        for (int i = 2; i <= num; ++i) {
            res[i] = res[i/2] + res[i%2];
        }
        return res;
    }

};

int main() {
    Solution sol;
    for (int i = 0; i < 10; ++i) {
        auto res = sol.countBits2(i);
        std::cout << i << ": ";
        std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    }
    return 0;
}