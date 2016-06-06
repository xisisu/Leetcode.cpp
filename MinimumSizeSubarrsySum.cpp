//
// Created by xisisu on 6/5/16.
//

/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum
 * ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int minSubArrayLen(int s, std::vector<int>& nums) { // 124 ms
        int res = INT32_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            bool found = false;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum >= s) {
                    res = std::min(res, j-i+1);
                    if (res == 1) { return res; }
                    found = true;
                    break;
                }
            }
            if (!found) { break; }
        }

        return INT32_MAX == res ? 0 : res; // in case the array is empty
    }

public:
    int minSubArrayLen2(int s, std::vector<int>& nums) { // 4 ms
        int start = 0, end = 0, sum = 0, res = INT32_MAX;
        while (end < nums.size()) {
            sum += nums[end];
            ++end;
            while (sum >= s && start < end) {
                res = std::min(res, end-start);
                sum -= nums[start];
                ++start;
            }
        }

        return INT32_MAX == res ? 0 : res;
    }

};

int main() {
    Solution sol;
    std::vector<int> data = {5,4,3,2,1};

    for (auto const& val : {11, 5}) {
        std::cout << sol.minSubArrayLen(val, data) << ", " << sol.minSubArrayLen2(val, data) << std::endl;
    }

    return 0;
}