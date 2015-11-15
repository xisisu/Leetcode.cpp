//
// Created by Sisu on 11/15/2015.
//

/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) { // 4 ms
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[res++] = nums[i];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1, 2, 3, 4, 1, 2, 3, 4};
    std::cout << sol.removeElement(tests, 1) << std::endl;
    return 0;
}