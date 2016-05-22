//
// Created by xisisu on 5/21/16.
//

/*
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run
 * in linear time and in O(1) space.
 */

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int> const& nums) { // 40 ms
        if (nums.size() < 2) { return nums; }

        std::map<int, int> map;
        std::set<int> set;
        for (auto const& val : nums) {
            if (++map[val] > (nums.size()/3)) { set.insert(val); }
        }

        return std::vector<int>(set.begin(), set.end());
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
        {}
        , {2,2}
        , {1,1,1,1,1}
        , {1,2,3}
        , {1,2,3,4,5}
        , {1,2}
        , {1,1,1,1,1,1,2,3}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        auto res = sol.majorityElement(test);
        std::cout << "result: ";
        std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl << std::endl;
    }

    return 0;
}