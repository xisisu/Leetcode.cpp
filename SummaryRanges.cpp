//
// Created by Sisu on 3/1/2016.
//

/*
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

class Solution {
public:
    std::string to_string(int val) {
        if (val == 0) { return "0"; }
        std::string res = "";
        while (val > 0) {
            res = std::string(1, ('0'+val%10)) + res;
            val /= 10;
        }
        return res;
    }

    std::string getRange(int start, int pre) {
        std::string s = "";
        if (pre == start) {
            s = to_string(start);
        } else {
            s = to_string(start) + "->" + to_string(pre);
        }
        return s;
    }

    std::vector<std::string> summaryRanges(std::vector<int>& nums) { // 0 ms
        if (nums.empty()) { return std::vector<std::string>(); }

        int start = nums[0];
        int pre = start;
        std::vector<std::string> result;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == pre+1) {
                pre = nums[i];
            } else { // now we found a stop, from start to pre
                result.push_back(getRange(start, pre));
                start = nums[i];
                pre = start;
            }
        }
        result.push_back(getRange(start, pre));

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {0}
            , {0,1,2,3,4,5}
            , {1,3,5,7,9}
            , {0,1,2,3,4,9}
    };

    for (auto test : tests) {
        std::cout << "input: ";
        for (auto const& item : test) {
            std::cout << item << ", ";
        }
        std::cout << std::endl;

        auto res = sol.summaryRanges(test);
        std::cout << "result: ";
        for (auto const& item : res) {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}