//
// Created by xisisu on 6/27/16.
//

/*
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 *
 * Formally the function should:
 * Return true if there exists i, j, k
 * such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
 * Your algorithm should run in O(n) time complexity and O(1) space complexity.
 *
 * Examples:
 * Given [1, 2, 3, 4, 5],
 * return true.
 *
 * Given [5, 4, 3, 2, 1],
 * return false.
 */

#include <iostream>
#include <iterator>
#include <vector>

class Solution {
public:
    bool increasingTriplet(std::vector<int> const& nums) { // 8 ms
        /*
         * just use two arrays to represent left contains smaller, or right contains larger
         */
        if (nums.size() < 3) { return false; }
        std::vector<bool> left(nums.size(), false);
        int minSofar = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > minSofar) { left[i] = true; }
            minSofar = std::min(minSofar, nums[i]);
        }

        std::vector<bool> right(nums.size(), false);
        int maxSofar = nums.back();
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] < maxSofar) { right[i] = true; }
            maxSofar = std::max(maxSofar, nums[i]);
        }

        for (int i = 1; i < nums.size()-1; ++i) {
            if (left[i] && right[i]) { return true; }
        }

        return false;
    }

public:
    // cleaver!!! if a<b exists, we only record b is enough, and use a to record next!
    bool increasingTriplet2(std::vector<int> const& nums) { // 2 ms
        auto a = INT32_MAX, b = INT32_MAX;
        for (auto const& val : nums) {
            if (val <= a) { a = val; }
            else if (val <= b) { b = val; }
            else { return true; }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1,2}
            , {1,2,2}
            , {1,2,3}
            , {100,90,95,80,85,70,75}
            , {100,90,95,80,85,70,75,76}
            , {100,90,95,80,96}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << ". output: " << sol.increasingTriplet(test) << sol.increasingTriplet2(test) << std::endl;
    }

    return 0;
}