//
// Created by Sisu on 11/22/2015.
//

/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int search(std::vector<int> const& nums, int target) { // 4 ms
        if (nums.empty()) { return -1; }

        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            auto mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[low] <= nums[mid]) { // left part is normal
                if (nums[low] <= target && target < nums[mid]) { high = mid-1; }
                else { low = mid + 1; }
            } else { // right part is normal
                if (nums[mid] < target && target <= nums[high]) { low = mid+1; }
                else { high = mid - 1;}
            }
        }
        return -1;
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

        std::cout << "output: " << sol.search(test, 3) << std::endl << std::endl;
    }

    return 0;
}