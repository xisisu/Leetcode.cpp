//
// Created by Sisu on 3/19/2016.
//

/*
 * Given a list of non negative integers, arrange them such that they form the largest number.
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#include "Common.h" // to_string

class Solution {

private:
    static long long combine(int i, int j) {
        if (i == 0) { return j; }
        if (j == 0) { return i*10; } // note the difference here!

        auto temp = j, scale = 1;
        while (temp > 0) { temp/= 10; scale *= 10; }
        return long(i)*scale + j;  // note the conversion here!!!
    }

struct compare {
    bool operator() (int i, int j) {
        auto a = combine(i, j), b = combine(j, i);
        return a > b;
    }

//    bool operator() (int i, int j) {
//        /*
//         * this method is not correct. It is hard to code this way because when length are different, too many cases
//         * for exampel, 91 vs 9, we should favor 9
//         * but 19 vs 1, we should favor 19.
//         */
//        if (i == 0) { return false; } // consider when i is 0!
//        std::stack<int> istack, jstack;
//        while (i > 0) { istack.push(i%10); i /= 10; }
//        while (j > 0) { jstack.push(j%10); j /= 10; }
//
//        while (!istack.empty() && !jstack.empty()) {
//            if (istack.top() == jstack.top()) { istack.pop(); jstack.pop(); }
//            else { return istack.top() > jstack.top(); }
//        }
//
//        return istack.empty();
//    }
} cumstumeCompare;

public:
    std::string largestNumber(std::vector<int> & nums) { // 4 ms
        std::sort(nums.begin(), nums.end(), cumstumeCompare);
        if (nums.empty() || nums[0] == 0) { return "0"; } // consider all 0 cases!
        std::string res = "";
        for (auto const & val: nums) { res += to_string(val); }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
            , {1,2,3,4,5,0}
            , {0,9,8,7,6,5,4,3,2,1}
            , {3,30,34,5,9}
            , {98, 9}
            , {19, 1}
            , {999999998,999999997,999999999} // test overflow
    };

    std::ostream_iterator<int> out_it(std::cout, ", ");
    for (auto& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), out_it);
        std::cout << std::endl << "res: " << sol.largestNumber(test) << std::endl << std::endl;
    }

    return 0;
}