//
// Created by Sisu on 11/28/2015.
//

/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional
 * elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) { // 4 ms
        int idx = m+n-1;
        --m; --n;
        while (idx >= 0) {
            if (n < 0) { return; }
            if (m < 0) {
                while (n >= 0) {
                    nums1[idx--] = nums2[n--];
                }
                return;
            }

            nums1[idx--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> num1 = {1,2};
    std::vector<int> num2 = {4,5};
    std::vector<int> res = num1;
    res.resize(num1.size()+ num2.size(), num2.size());
    sol.merge(res, num1.size(), num2, num2.size());
    for (const auto &item : res) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
    return 0;
}