//
// Created by Sisu on 3/20/2016.
//

/*
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    bool search(std::vector<int> const& nums, int target) { // 11 ms
        /*
         * note it could be that nums[low] == nums[mid] == nums[high] != target, it is still a valid case and we need
         * to keep searching
         */
        if (nums.empty()) { return false; }

        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            auto mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[low] == nums[mid]) {
                ++low;
                while (low <= mid && nums[low] == nums[low-1]) { ++low; }
            } else if (nums[high] == nums[mid]) {
                --high;
                while (high >= mid && nums[high] == nums[high+1]) { --high; }
            } else if (nums[low] < nums[mid]) { // left part is normal
                if (nums[low] <= target && target < nums[mid]) { high = mid-1; }
                else { low = mid + 1; }
            } else { // right part is normal
                if (nums[mid] < target && target <= nums[high]) { low = mid+1; }
                else { high = mid - 1;}
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
        {}
        , {1}
        , {1, 2}
        , {2, 1}
        , {4,4,4,4,0,1,2,2,2,2,3}
        , {0,1,2,2,2,2,2,3,4,4,4,4,4}
        , {3,4,0,0,0,0,0,0,1,2,2,2,2,2}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "output: " << sol.search(test, 3) << std::endl << std::endl;
    }

    return 0;
}