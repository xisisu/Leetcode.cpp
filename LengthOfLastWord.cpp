//
// Created by Sisu on 11/28/2015.
//

/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example,
 * Given s = "Hello World",
 * return 5.
 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLastWord(std::string s) { // 4 ms
        auto lastWordEnd   = s.find_last_not_of(' ');
        if (lastWordEnd == std::string::npos) { return 0; } // empty string or string with all space
        auto lastWordStart = s.find_last_of(' ', lastWordEnd);
        if (lastWordStart == std::string::npos) { return lastWordEnd + 1; }
        return lastWordEnd - lastWordStart;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
              ""
            , "    "
            , "Hello world"
            , "helloworld"
            , "helloWorld    "
            , "   helloworld     "
    };

    for (const auto &item : tests) {
        std::cout << item << ", " << sol.lengthOfLastWord(item) << std::endl;
    }
    return 0;
}