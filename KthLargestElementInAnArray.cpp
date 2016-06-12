//
// Created by xisisu on 6/12/16.
//

/*
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order,
 *  not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int> const& nums, int k) { // 20 ms
        if (k < 1 || k > nums.size()) { return INT32_MIN; }
        auto data = nums;
        sort(data.begin(), data.end());
        return data[data.size()-k];
    }

public:
    int findKthLargest2(std::vector<int> const& nums, int k) { // 20 ms
        /*
         * construct a min heap,
         * if size is less than k, push to heap
         * otherwise, compare k with the current element (k is the smallest one in the heap)
         *  if k is smaller than current one, pop k, insert val
         */
        std::priority_queue<int, std::vector<int>, std::greater<int> > q;
        for (auto val : nums) {
            if (q.size() < k) { q.push(val); }
            else {
                if (q.top() < val) {
                    q.pop();
                    q.push(val);
                }
            }
        }

        return q.top();
    }
};

int main() {
    Solution sol;
    std::vector<int> const data = {3,2,1,5,6,4,3,3,3};
    for (int i = 1; i < data.size(); ++i) {
        std::cout << i << ", " << sol.findKthLargest(data, i) << ", " << sol.findKthLargest2(data, i) << std::endl;
    }
    return 0;
}