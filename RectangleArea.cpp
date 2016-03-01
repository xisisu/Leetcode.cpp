//
// Created by Sisu on 2/29/2016.
//

/*
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * Rectangle Area
 * Assume that the total area is never beyond the maximum possible value of int.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) { // 32 ms
        int min_x = std::max(A, E);
        int min_y = std::max(B, F);
        int max_x = std::min(C, G);
        int max_y = std::min(D, H);
        int common = (max_x - min_x) * (max_y - min_y);
        if (max_x < min_x || max_y < min_y) { common = 0; } // tricky part! both can be negative and common is positive

        int area1  = (C - A) * (D - B);
        int area2  = (G - E) * (H - F);

        return area1 + area2 - common;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {0,0,0,0,0,0,0,0}
            , {0,0,0,0,-1,-1,1,1}
            , {-3,0,3,4,0,-1,9,2}
            , {1,0,2,1,3,0,4,1} // no common part
            , {-2,-2,2,2,3,3,4,4}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        for (auto const& item: test) {
            std::cout << item << ", ";
        }
        std::cout << std::endl << "result: " << sol.computeArea(test[0], test[1], test[2], test[3], test[4], test[5], test[6], test[7]) << std::endl << std::endl;
    }

    return 0;
}