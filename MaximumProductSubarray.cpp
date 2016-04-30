//
// Created by Sisu on 4/25/2016.
//

/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int maxProduct(std::vector<int> const& nums) { // 8 ms
        /*
         * since numbers are all integers, so it can only grow larger for the product (unless it is 0)
         * use minVal and maxVal to deal with the sign issue, typical dp problem
         */
        if (nums.empty()) { return 0; }
        if (nums.size() == 1) { return nums[0]; }
        int minVal = 0, maxVal = 0, res = 0;
        for (auto const& val : nums) {
            if (val == 0) {
                minVal = 0;
                maxVal = 0;
            } else if (val > 0) {
                minVal = std::min(0, val * minVal);
                maxVal = std::max(val, val * maxVal);
            } else {
                auto temp = minVal;
                minVal = std::min(val, val * maxVal);
                maxVal = std::max(0, val * temp);
            }
            res = std::max(res, maxVal);
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {1}
            , {-1}
            , {-10, 10}
            , {10, -10, 10}
            , {-10, 10, -10}
            , {2,3,-2,4}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "result: " << sol.maxProduct(test) << std::endl << std::endl;
    }

    return 0;
}