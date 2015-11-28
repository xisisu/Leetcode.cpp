//
// Created by Sisu on 11/28/2015.
//

/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 */

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string countAndSay(int n) { // 0 ms
        std::string cur = "1", nxt = "";

        for (int i = 1; i < n; ++i) {
            char val = cur[0];
            int count = 1;
            for (int j = 1; j < cur.size(); ++j) {
                if (val == cur[j]) { ++count; }
                else {
                    nxt.push_back('0' + count);
                    nxt.push_back(val);
                    val = cur[j];
                    count = 1;
                }
            }
            nxt.push_back('0' + count);
            nxt.push_back(val);
            cur = nxt;
            nxt = "";
        }

        return cur;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ", " << sol.countAndSay(i) << std::endl;
    }
    return 0;
}