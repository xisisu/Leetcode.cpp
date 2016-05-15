//
// Created by xisisu on 5/14/16.
//

/*
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that the
 * difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int> const& nums, int k, int t) { // overTime
        if (nums.size() <= 1 || k <= 0 || t < 0) { return false; }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = std::max(0, i-k); j < i; ++j) {
                if (std::abs((long)nums[i]-(long)nums[j]) <= t) { return true; }
            }
        }
        return false;
    }

public:
    bool containsNearbyAlmostDuplicate2(std::vector<int> const& nums, int k, int t) { // 24 ms
        if (nums.size() <= 1 || k <= 0 || t < 0) { return false; }
        /*
         * create reverse index, then sort nums by value. if any adjencent value has index less than k and value diff
         * less than t, then we found 1
         * Note we can not use map, as there are duplicate values!
         */
        std::vector<std::pair<int, int>> reverseIndex;
        for (int i = 0; i < nums.size(); ++i) { reverseIndex.push_back({nums[i], i}); }

        sort(reverseIndex.begin(), reverseIndex.end());
        for (int i = 1; i < reverseIndex.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (std::abs( (long)reverseIndex[i].first-(long)reverseIndex[j].first ) > t) { break; } // trick here! :)
                if (std::abs( reverseIndex[i].second - reverseIndex[j].second ) <= k) { return true; }
            }
        }
        return false;
    }

private:
    int getBucketId(int val, int width) {
        return val / width;
    }

public:
    bool containsNearbyAlmostDuplicate3(std::vector<int> const& nums, int k, int t) { // 36 ms
        if (nums.size() <= 1 || k <= 0 || t < 0) { return false; }
        /*
         * Use bucket sort to solve the problem, preDefine a bucket width of t. O(n)
         * Note: t == 0 is a valid input. As a result, we use t+1 as the width.
         * Since we are checking both left, right, and same bucket, we should be safe.
         */
        std::unordered_map<int, int> buckets; // bucket id -> index
        for (int i = 0; i < nums.size(); ++i) {
            auto bucket = getBucketId(nums[i], t+1);
            if ( ( buckets.count(bucket)   && (std::abs((long)nums[i] - (long)nums[buckets[bucket]])   <= t) ) || // same
                 ( buckets.count(bucket-1) && (std::abs((long)nums[i] - (long)nums[buckets[bucket-1]]) <= t) ) || // left
                 ( buckets.count(bucket+1) && (std::abs((long)nums[i] - (long)nums[buckets[bucket+1]]) <= t) ))   // right
            { return true; }

            buckets[bucket] = i; // insert into bucket

            if (i >= k) { // remove old ones
                auto oldBucket = getBucketId(nums[i-k], t+1);
                buckets.erase(oldBucket);
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::pair<int, int>, std::vector<int>>> tests = {
            {{5, 0}, {1,2,3,4,5,6,7,8}}
            , {{1,1}, {2,1}}
            , {{1, 2147483647}, {-1, 2147483647}}
            , {{1,1}, {1,3,1}}
    };

    for (auto const& test : tests) {
        std::cout << test.first.first << ", " << test.first.second << ". \t\t";
        std::copy(test.second.begin(), test.second.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl << sol.containsNearbyAlmostDuplicate3(test.second, test.first.first, test.first.second) << std::endl;
    }

    return 0;
}