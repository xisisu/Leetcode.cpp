//
// Created by Sisu on 3/20/2016.
//

/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
 * It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) { // 19 ms
        if (nums.size() < 3) { return nums.size(); }
        int res = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[res-1] || nums[i] != nums[res-2]) { nums[res++] = nums[i]; }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1,2,3}
            , {1,1,2,2,3}
            , {1,1,1,2,2,3}
            , {1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3}
    };

    std::ostream_iterator<int> out(std::cout, ",");
    for (auto& test : tests) {
        std::cout << "before: ";
        std::copy(test.begin(), test.end(), out);
        auto res = sol.removeDuplicates(test);
        std::cout << std::endl << "after: ";
        std::copy(test.begin(), test.end(), out);
        std::cout << "size: " << res << std::endl << std::endl;
   }

    return 0;
}