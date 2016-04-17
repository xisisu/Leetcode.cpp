//
// Created by Sisu on 4/16/2016.
//

/*
 *
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

class Solution {
public:
    int singleNumber2(std::vector<int> const& nums) { // 12 ms
        /*
         * bit operation
         * ones: bits that have appeared odd times
         * twos: bits that have appeared twice
         * common: appear third times, so not in ones and twos
         */
        int ones = 0, twos = 0;
        for (auto const& val : nums) {
            twos |= (ones & val);        // ones&val gives bit appeared even times, add it to twos
            ones ^= val;                 // ones records all the bit appears odd times
            int common = (ones & twos); // find common bits (appear three times)
            ones &= ~common;             // remove common bits
            twos &= ~common;             // remove common bits
        }
        return ones;
    }

public:
    int singleNumber(std::vector<int> const& nums) { // 24 ms
        std::unordered_map<int, int> map;
        for (auto const& val : nums) {
            map[val]++;
            if (map[val] == 3) { map.erase(val); }
        }
        if (map.size() != 1) { return INT32_MIN; }
        for (auto const& val : map) { return val.first; }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {3,3,3,2}
            , {1,2,3,1,2,3,1,2,3,4}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        std::cout << "output: " << sol.singleNumber2(test) << std::endl << std::endl;
    }

    return 0;
}