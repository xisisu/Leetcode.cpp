//
// Created by Sisu on 11/15/2015.
//

/*
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) { // 4 ms
        if (haystack == needle) { return 0; }
        if (haystack.size() < needle.size()) { return -1; }
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            auto cur = i;
            while (cur-i < needle.size() && haystack[cur] == needle[cur-i]) {
                ++cur;
            }
            if (cur-i == needle.size()) { return i; }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"mississippi"};
    for (const auto& item: tests) {
        std::cout << item << ", " << sol.strStr(item, "pi") << std::endl;
    }
    return 0;
}