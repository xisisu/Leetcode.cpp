//
// Created by Sisu on 3/19/2016.
//

/*
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
 * with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * click to show follow up.
 * Follow up:
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's,
 * then 1's and followed by 2's.
 * Could you come up with an one-pass algorithm using only constant space?
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        auto red = 0, white = 0, blue = 0;
        for (auto const& val : nums) {
            if (val == 0) { ++red; }
            else if (val == 1) { ++white; }
            else { ++blue; }
        }
        for (auto& val : nums) {
            if (red) { val = 0; --red; }
            else if (white) { val = 1; --white; }
            else { val = 2; }
        }
    }

public:
    void sortColors2(std::vector<int>& nums) { // 4 ms
        /*
         * scan from both left and right
         * find first left which is non 0, and first right which is non 2, four combinations
         * left vs: right
         *  -- 2, 0: swap
         *  -- 1, 1: use another variable to find the first non 1 element in between, and sawp
         *  -- 1, 0: swap
         *  -- 2, 1: swap
         */
        if (nums.size() < 2) { return; }
        int red = 0, blue = nums.size()-1, non_white = -1;

        while (red < blue) {
            while (nums[red] == 0 && red < blue) { ++red; }
            while (nums[blue] == 2 && red < blue) { --blue; }
            if (red >= blue) { return; }

            if (nums[red] == 2 || nums[blue] == 0) {
                std::swap(nums[red], nums[blue]);
            } else { // nums[red] = nums[blue] = white
                non_white = std::max(non_white, red+1); // simple optimization to remember last position
                bool done = true;
                while (non_white < blue) {
                    if (nums[non_white] == 1) { ++non_white; }
                    else if (nums[non_white] == 0) { // find a red one, swap with num[red]
                        std::swap(nums[red++], nums[non_white]);
                        done = false;
                        break;
                    } else { // find a blue one, swap with num[blue]
                        std::swap(nums[blue--], nums[non_white]);
                        done = false;
                        break;
                    }
                }
                if (done) { return; }
            }
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {0,0,0,0,0,0,0}
            , {0,0,0,0,1,1,1,1,2,2,2}
            , {2,1,0,1,2,0,2,1}
            , {1,1,1,1,1,1}
            , {1,2,0}
    };

    std::ostream_iterator<int> out(std::cout, ",");
    for (auto & test : tests) {
        std::cout << "before: ";
        std::copy(test.begin(), test.end(), out);
        std::cout << std::endl << "after: ";

        auto try1 = test;
        sol.sortColors(try1);
        std::copy(try1.begin(), try1.end(), out);
        std::cout << std::endl << "after: ";

        auto try2 = test;
        sol.sortColors2(try2);
        std::copy(try2.begin(), try2.end(), out);
        std::cout << std::endl << std::endl;
    }

    return 0;
}
