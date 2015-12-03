//
// Created by Sisu on 12/2/2015.
//

/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
 * stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum
 * amount of money you can rob tonight without alerting the police.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

class Solution {
public:
    // typical dp problem
    int rob(std::vector<int>& nums) { // 0 ms
        int N = nums.size();
        if (N == 0) { return 0; }
        if (N == 1) { return nums[0]; }

        int dp[N];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < N; ++i) {
            if (i == 0) { dp[i] = nums[i]; }
            else if (i == 1) { dp[i] = std::max(nums[i], nums[i-1]); }
            else { dp[i] = std::max(nums[i] + dp[i-2], dp[i-1]); }
        }

        return std::max(dp[N-1], dp[N-2]);
    }

    // this version records which house to rob
    int rob_1(std::vector<int>& nums) { // 0 ms
        int N = nums.size();
        if (N == 0) { return 0; }
        if (N == 1) { return nums[0]; }

        int dp[N];
        memset(dp, 0, sizeof dp);
        bool take[N];
        memset(take, false, sizeof take);
        for (int i = 0; i < N; ++i) {
            if (i == 0) {
                dp[0] = nums[0];
                take[0] = true;
            } else if (i == 1) {
                dp[1] = std::max(nums[1], nums[0]);
                take[1] = nums[1] > nums[0] ? true : false;
            } else {
                if (nums[i] + dp[i-2] > dp[i-1]) { // note if it is equal, we do not take it
                    dp[i] = nums[i] + dp[i-2];
                    take[i] = true;
                } else {
                    dp[i] = dp[i-1];
                    take[i] = false;
                }
            }
        }

        auto cur = dp[N-1] > dp[N-2] ? N-1 : N-2;
        while (cur >= 0) {
            if (take[cur]) {
                std::cout << "(" << cur << "," << nums[cur] << "), ";
                cur -= 2;
            } else {
                --cur;
            }
        }

        return std::max(dp[N-1], dp[N-2]);
    }

    // since we care only about total money, the whole array is not necessary
    int rob_2(std::vector<int>& nums) { // 0 ms
        int include = 0, exclude = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto temp = include;
            include = exclude + nums[i];
            exclude = std::max(temp, exclude);
        }

        return std::max(include, exclude);
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {2,1,1,2};
    std::cout << sol.rob_2(tests) << std::endl;
    return 0;
}