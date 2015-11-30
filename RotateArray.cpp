//
// Created by Sisu on 11/29/2015.
//

/*
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * [show hint]
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * Related problem: Reverse Words in a String II
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) { // 24 ms
        int idx = 0, cur = 0, distance = 0, count = 0;

        // similar to quick sort
        while (count++ < nums.size()) {
            int nxt = (idx+k) % nums.size();
            int tmp = nums[nxt];
            nums[nxt] = nums[cur];
            nums[cur] = tmp;
            idx = nxt;

            // notice the case when nums.size() / k == 0, we need to run multiple loops
            distance = (distance+k)%nums.size();
            if (distance == 0) {
                idx = (idx+1) % nums.size();
                cur = idx;
            }
        }
    }

    void rotate_2(std::vector<int>& nums, int k) { // 24 ms
        if (nums.size() == 0 || k % nums.size() == 0) { return; }
        k %= nums.size();
        std::vector<int> res(nums.size(), 0);
        for (int i = 0; i < res.size(); ++i) {
            int j = (i-k+nums.size()) % nums.size();
            res[i] = nums[j];
        }
        nums = res;
    }

    void rotate_3(std::vector<int>& nums, int k) { // 24 ms
        if (nums.size() == 0 || k % nums.size() == 0) { return; }
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3};
    sol.rotate_3(tests, 4);
    for (const auto &val : tests) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;
    return 0;
}
