//
// Created by Sisu on 4/16/2016.
//

/*
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int singleNumber(std::vector<int> const & nums) { // 16 ms
        int a = 0;
        for (auto const& val : nums) { a ^= val; }
        return a;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {1,2,3,4,5,6,7,8,9,10,1,3,4,5,6,7,8,9,10}
            , {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,8,9,10}
            , {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,7,8,9,10}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "output: " << sol.singleNumber(test) << std::endl << std::endl;
    }

    return 0;
}