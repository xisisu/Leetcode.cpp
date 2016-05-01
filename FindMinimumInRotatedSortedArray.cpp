//
// Created by Sisu on 4/30/2016.
//

/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int findMin(std::vector<int> const& nums) { // 4 ms
        if (nums.empty()) { return 0;}

        int low = 0, high = nums.size()-1;
        int res = INT32_MAX;
        while (low <= high) {
            auto mid = low + (high-low) / 2;
            if (nums[low] <= nums[mid]) { // left part is normal
                res = std::min(res, nums[low]);
                low = mid + 1;
            } else { // right part is normal
                res = std::min(res, nums[mid]);
                high = mid - 1;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
              {}
            , {1}
            , {1, 2}
            , {2, 1}
            , {4,0,1,2,3}
            , {0,1,2,3,4}
            , {3,4,0,1,2}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "output: " << sol.findMin(test) << std::endl << std::endl;
    }

    return 0;
}