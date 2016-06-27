//
// Created by xisisu on 6/26/16.
//

/*
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <queue>

class Compare {
public:
    bool operator() (std::pair<int, int> a, std::pair<int, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int> const& nums, int k) { // 36 ms
        std::unordered_map<int, int> map;
        for (auto const& val : nums) { ++map[val]; }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> queue;
        for (auto const it : map) {
            queue.push(std::pair<int, int>(it.first, it.second));
        }

        std::vector<int> res(k, 0);
        for (int i = 0; i < k; ++i) {
            auto cur = queue.top();
            queue.pop();
            res[i] = cur.first;
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {1,1,1,2,2,3}
    };

    for (auto const& test : tests) {
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        auto res = sol.topKFrequent(test, 2);
        std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    }

    return 0;
}