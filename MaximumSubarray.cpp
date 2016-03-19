//
// Created by Sisu on 3/19/2016.
//

/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <iostream>
#include <vector>
#include <limits>
#include <iterator>

class Solution {
public:
    int maxSubArray(std::vector<int> const& nums) { // 12 ms
        /*
         * typical dp problem
         * if all negative, would still pick one instead of returning 0
         * if empty array, would return int_min
         */
        int cur = 0, res = std::numeric_limits<int>::min();
        for (auto const& val : nums) {
            cur += val;
            res = std::max(res, cur);
            cur = std::max(cur, 0);
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            { 0, 0, 0, 0, 0}
            , {}
            , { 1 }
            , { -1 }
            , { -4, -3, -2, -1 }
            , { 4, 3, 2, 1 }
            , { -2, 1, -3, 4, -1, 2, 1, -5, 4 }
    };

    std::ostream_iterator<int> out_it(std::cout, ", ");
    for (auto const& test: tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), out_it);
        std::cout << std::endl << "res: " << sol.maxSubArray(test) << std::endl << std::endl;
    }

    return 0;
}