//
// Created by Sisu on 12/3/2015.
//

/*
 * Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
 * such that nums[i] = nums[j] and the difference between i and j is at most k.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) { // 32 ms
        if (k == 0) { return false; }
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            // delete the i-k th item from the map
            if (i > k) { --map[nums[i-k-1]]; }
            if (map[nums[i]] > 0) { return true; }
            ++map[nums[i]];
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,1};
    std::cout << sol.containsNearbyDuplicate(tests, 1) << std::endl;
    return 0;
}