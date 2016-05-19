//
// Created by xisisu on 5/18/16.
//

/*
 * Given two arrays, write a function to compute their intersection.
 *
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 *
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */

#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    std::vector<int> intersection(std::vector<int> const& nums1, std::vector<int> const& nums2) { // 16 ms
        if (nums1.empty() || nums2.empty()) { return {}; }
        std::set<int> val1(nums1.begin(), nums1.end());
        std::set<int> val2(nums2.begin(), nums2.end());
        std::vector<int> res;
        for (auto const& val : val1) {
            if (val2.count(val)) { res.push_back(val); }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1,2,2,1};
    std::vector<int> nums2 = {2,2};

    auto res = sol.intersection(nums1, nums2);
    for (auto const& val : res) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    return 0;
}