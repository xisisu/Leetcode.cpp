//
// Created by Sisu on 3/19/2016.
//

/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * For example:
 * A = [2,3,1,1,4], return true.
 * A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    bool canJump(std::vector<int> const& nums) { // 16 ms
        if (nums.size() <= 1) { return true; }
        int furthest = 0;
        for (int i = 0; i < nums.size(); ++i) {
            furthest = std::max(furthest, i + nums[i]);
            if (furthest >= nums.size()-1) { return true; }
            if (furthest <= i) { return false; }
        }
        return furthest >= nums.size();
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {0}
            , {1}
            , {2,0,0}
            , {0,100}
            , {1,0,100}
            , {2,3,1,1,4}
            , {3,2,1,0,4}
    };

    std::ostream_iterator<int> out(std::cout, ", ");
    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), out);
        std::cout << std::endl << sol.canJump(test) << std::endl << std::endl;
    }

    return 0;
}

