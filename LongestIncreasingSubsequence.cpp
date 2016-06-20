//
// Created by xisisu on 6/19/16.
//

/*
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than
 * one LIS combination, it is only necessary for you to return the length.
 *
 * Your algorithm should run in O(n2) complexity.
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) { // 116 ms
        if (nums.empty()) { return 0; }
        std::vector<int> dp(nums.size()+1, 1); // at least has size 1
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) { dp[i] = std::max(dp[i], dp[j]+1); }
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }

private:
    int search(std::vector<int>& dp, int len, int val) {
        /*
         * binary search to find the val idx
         */
        int start = 0;
        while (start <= len) {
            int mid = start + (len-start)/2;
            if (dp[mid] == val) { return mid; }
            else if (dp[mid] < val) { start = mid+1; }
            else { len = mid-1; }
        }
        return start;
    }

public:
    int lengthOfLIS2(std::vector<int>& nums) { // 4 ms
        if (nums.empty()) { return 0; }
        /*
         * dp here stores the current smallest value that has length i.
         * For example, dp[0] stores the minimal val with len 1
         * dp[1] stores the minimal end val with len 2, as a result, if a val is larger than the current max len, we
         * can update it
         */
        std::vector<int> dp(nums.size()+1, INT32_MAX);
        int len = 0;
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp[len]) {
                dp[++len] = nums[i];
            } else {
                int idx = search(dp, len, nums[i]);
                dp[idx] = nums[i];
            }
        }
        return len+1;
    }
};

int main() {
    Solution sol;
    std::vector<int> data = {10,9,2,5,3,7,101,18};

    std::cout << sol.lengthOfLIS2(data) << std::endl;
    return 0;
}