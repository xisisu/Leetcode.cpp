//
// Created by xisisu on 6/17/16.
//

/*
 * Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 *
 * Hint:
 *
 * Expected runtime complexity is in O(log n) and the input is sorted.
 */

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) { // 12 ms
        /*
         * just a binary search, find last(largest) data[idx] <= idx+1
         */
        if (citations.empty()) { return 0; }
        int const M = citations.size();
        int res = 0;
        int low = 0, high = citations.size()-1;
        while (low <= high) {
            auto mid = low + (high-low)/2;
            if (citations[mid] >= M-mid) {
                res = M-mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {0,0,0,0,0}
            , {3,0,6,1,5}
            , {1,1,1,1,1,1,1,1,1,1,1,1}
            , {1,1,1,1,1,1,1,1,1,1,1,1,1,2,2}
    };

    for (auto& test : tests) {
        std::sort(test.begin(), test.end());
        std::cout << "input : ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        std::cout << "output: " << sol.hIndex(test) << std::endl << std::endl;
    }

    return 0;
}