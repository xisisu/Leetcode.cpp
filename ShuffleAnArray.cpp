//
// Created by xisisu on 9/24/16.
//

/*
 * Shuffle a set of numbers without duplicates.
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 */

#include <iostream>
#include <vector>

class Solution {
public:
    Solution(std::vector<int> nums) { // 292 ms
        _original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return _original;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        std::vector<int> res = _original;
        for (int i = 0; i < res.size(); ++i) {
            long j = random() % res.size();
            std::swap(res[i], res[j]);
        }
        return res;
    }

private:
    std::vector<int> _original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */