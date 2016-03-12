//
// Created by Sisu on 11/5/2015.
//

/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
 * which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 */

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>const & height) { // 28 ms
        if (height.size() < 2) { return 0; }
        int s = 0, e = height.size()-1;
        int res = 0;

        while (s < e) {
            int cur = (e-s) * std::min(height[s], height[e]);
            res = std::max(res, cur);

            if (height[s] < height[e]) {
                while (s < e && height[s] > height[s+1]) { ++s; }
                ++s;
            } else {
                while (s < e && height[e] > height[e-1]) { --e; }
                --e;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1,2,3,4,5,6,7}
            , {1,2,7,7,2,1}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        for (auto const& val : test) {
            std::cout << val << ", ";
        }
        std::cout << std::endl << "result: " << sol.maxArea(test) << std::endl << std::endl;
    }

    return 0;
}