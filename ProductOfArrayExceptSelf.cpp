//
// Created by xisisu on 6/1/16.
//


/*
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product
 * of all the elements of nums except nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the
 * purpose of space complexity analysis.)
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int> const& nums) { // 68 ms
        std::vector<int> result(nums.size(), 0);
        if (nums.size() < 2) { return result; }

        long long sum = 1;
        int zeroCount = 0;
        for (auto const& val : nums) {
            if (val == 0) { ++zeroCount; }
            else { sum *= val; }
        }

        if (zeroCount == 0) {
            for (int i = 0; i < nums.size(); ++i) { result[i] = sum / nums[i]; }
        } else if (zeroCount == 1) {
            for (int i = 0; i < nums.size(); ++i) { if (nums[i] == 0) { result[i] = sum; } }
        }

        return result;
    }

public:
    std::vector<int> productExceptSelf2(std::vector<int> const& nums) { // 60 ms
        if (nums.empty()) { return {}; }

        std::vector<int> result(nums.size(), 0);
        // calculate left
        for (int i = 0, left = 1; i < nums.size(); ++i) {
            result[i] = left;
            left *= nums[i];
        }
        // calculate right
        for (int i = nums.size()-1, right = 1; i >= 0; --i) {
            result[i] *= right;
            right *= nums[i];
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {0,0}
            , {0,1,2,3,4}
            , {0,4,3,2,1,0}
            , {1,1,1,1,1,1}
            , {2,2,2,2}
            , {1,2,3,4}
    };

    for (auto const& test : tests) {
        std::cout << "input : ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        auto res = sol.productExceptSelf(test);
        std::cout << "output: ";
        std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        auto res2 = sol.productExceptSelf(test);
        std::cout << "output: ";
        std::copy(res2.begin(), res2.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl << std::endl;
    }

    return 0;
}