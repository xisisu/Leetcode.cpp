//
// Created by Sisu on 3/4/2016.
//

/*
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */

#include <iostream>
#include <vector>
#include <map>

class NumArray {
public:
    NumArray(std::vector<int> &nums) { // 588 ms
        _sum.clear();
        _sum.resize(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            _sum[i] = (i == 0) ? nums[0] : _sum[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? _sum[j] : _sum[j] - _sum[i-1];
    }

private:
    std::vector<int> _sum;
};


int main() {
    std::vector<int> input = {-2, 0, 3, -5, 2, -1};
    NumArray arr(input);

    for (int i = 0; i < input.size(); ++i) {
        for (int j = i; j < input.size(); ++j) {
            std::cout << "(" << i << ", " << j << ") -> " << arr.sumRange(i, j) << std::endl;
        }
    }

    return 0;
}