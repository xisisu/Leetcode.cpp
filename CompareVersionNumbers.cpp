//
// Created by Sisu on 11/29/2015.
//

/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three",
 * it is the fifth second-level revision of the second first-level revision.
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

class Solution {
public:
    std::vector<int> splitVersions(std::string &s) {
        std::vector<int> res;
        if (s.empty()) { return res; }
        int cur = 0;
        for (const auto & c : s) {
            if (c == '.') { res.push_back(cur); cur = 0; }
            else { cur *= 10; cur += c-'0'; }
        }
        res.push_back(cur);
        return res;
    }

    int compareVersion(std::string version1, std::string version2) { // 0 ms
        auto a1 = splitVersions(version1);
        auto a2 = splitVersions(version2);
        int idx = 0;
        while (idx < std::min(a1.size(), a2.size())) {
            if (a1[idx] > a2[idx]) { return 1; }
            else if (a1[idx] < a2[idx]) { return -1; }
            ++idx;
        }
        // only 1 of the while loop will be executed
        // they are needed to compare "1.0" vs. "1.0.0.0.0"
        while (idx < a1.size()) {
            if (a1[idx++]) { return 1; }
        }
        while (idx < a2.size()) {
            if (a2[idx++]) { return -1; }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    std::cout << sol.compareVersion("0.1", "0.2") << std::endl;
    return 0;
}