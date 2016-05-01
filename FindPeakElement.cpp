//
// Created by Sisu on 4/30/2016.
//

/*
 * A peak element is an element that is greater than its neighbors.
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 * You may imagine that num[-1] = num[n] = -∞.
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 * Note:
 * Your solution should be in logarithmic complexity.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int findPeakElement(std::vector<int> const& nums) { // 8 ms
        if (nums.empty()) { return -1; }
        if (nums.size() == 1) { return 0; }

        int cur = 0;
        while (cur < nums.size()) {
            if ( (cur == 0 && nums[0] > nums[1]) ||
                  (cur == nums.size()-1 && nums[cur] > nums[cur-1]) ||
                  (nums[cur] > nums[cur-1] && nums[cur] > nums[cur+1]) )
            { return cur; }
            ++cur;
        }
        return -1;
    }

    int findPeakElement2(std::vector<int> const& nums) { // 8 ms
        // binary search solution
        if (nums.empty()) { return -1; }
        if (nums.size() == 1) { return 0; }

        int low = 0, high = nums.size()-1;
        while (low < high) {
            auto mid = low + (high-low)/2;
            if (nums[mid] < nums[mid+1]) { low = mid+1; } // in this case, there must exist a peak on the right side (since nums[n] is INT32_MIN)
            else { high = mid; } // in this case, there must exist a peak on left side (since nums[0] is INT32_MIN)
        }
        return low;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1,2,3}
            , {3,2,1}
            , {2,1,2}
            , {1,2,1}
    };

    for (auto const& test : tests) {
        std::cout << "input; ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "result: " << sol.findPeakElement2(test) << std::endl << std::endl;
    }

    return 0;
}