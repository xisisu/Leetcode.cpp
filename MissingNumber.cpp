//
// Created by xisisu on 6/12/16.
//

/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the
 * array.
 * For example,
 * Given nums = [0, 1, 3] return 2.
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space
 * complexity?
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) { // 36 ms
        /*
         * math problem, total sum is know, so easy to figure out.
         */
        auto maxVal = nums.size();
        auto expectedSum = maxVal * (1 + maxVal) / 2;
        for (auto const& val : nums) { expectedSum -= val; }
        return expectedSum;
    }
};

int main() {
    Solution sol;
    std::vector<int> data = {0,1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < data.size(); ++i) {
        auto input = data;
        input.erase(input.begin()+i);
        std::cout << i << ", " << sol.missingNumber(input) << std::endl;
    }

    return 0;
}
