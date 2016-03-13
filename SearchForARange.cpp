//
// Created by Sisu on 3/12/2016.
//

/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

#include <iostream>
#include <vector>

class Solution {
private:
    int findElement(std::vector<int>const & nums, int target, bool findFirst) { // 12 ms
        /*
         * nums is already sorted, typical binary search
         * if findFrist, return first matched element
         * if !findFirst, return last matched element
         */
        if (nums.empty()) { return -1; }
        if (nums.size() == 1) { return nums[0] == target ? 0 : -1; }

        int64_t low = 0, high = nums.size() -1;
        while (low <= high) {
            if (low == high) { return nums[low] == target ? low : -1;  }
            int64_t mid = low + (high-low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid;
            } else { // nums[mid] == target
                if (findFirst) {
                    if (mid == 0) { return 0; }
                    else if (nums[mid-1] != target) { return mid; }
                    else { high = mid; }
                } else {
                    if (mid == nums.size()-1) { return nums.size() - 1; }
                    else if (nums[mid+1] != target) { return mid; }
                    else { low = mid + 1; }
                }
            }
        }

        return -1;
    }

public:
    std::vector<int> searchRange(std::vector<int>const & nums, int target) {
        std::vector<int> res;
        res.push_back(findElement(nums, target, true));
        res.push_back(findElement(nums, target, false));

        return res;
    }
};

int main() {
    Solution sol;
    /* assuming target is always 2 */
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1, 1}
            , {2}
            , {2, 2}
            , {2,2,2,2,2}
            , {1,2,2,2,2,3}
            , {1,1,2,2,2,2,3}
            , {1,2,3}
    };

    for (auto const& test : tests) {
        std::cout << std::endl << "input; ";
        for (auto const& val : test) {
            std::cout << val << ", ";
        }
        auto res = sol.searchRange(test, 2);
        std::cout << std::endl << "result: ";
        for (auto const& val : res) {
            std::cout << val << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}