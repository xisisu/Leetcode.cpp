//
// Created by Sisu on 4/2/2016.
//

/*
 * Given an input string, reverse the string word by word.
 *
 * For example,
 *         Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Clarification:
 * What constitutes a word? A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces? Yes. However, your reversed string should not contain leading or trailing spaces.
 * How about multiple spaces between two words? Reduce them to a single space in the reversed string.
 */

#include <iostream>
#include <vector>

class Solution {
public:
    void reverseWords(std::string &s) { // 4 ms
        if (s.empty()) { return; }
        std::vector<std::string> res;

        size_t pos = 0;
        while (pos < s.size()) {
            auto start = s.find_first_not_of(' ', pos);
            if (start == std::string::npos) { break; }
            auto end = s.find_first_of(' ', start);

            if (end == std::string::npos) { res.push_back(s.substr(start)); break; }
            else { res.push_back(s.substr(start, end-start)); }
            pos = end;
        }

        s = "";
        if (res.empty()) { return; }
        for (int i = res.size()-1; i >= 0; --i) {
            if (i != res.size()-1) { s += " "; }
            s += res[i];
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "        single        "
            , "         "
            , "   hello         world       the  "
            , "hello world"
    };

    for (auto& test : tests) {
        std::cout << test << ", ";
        sol.reverseWords(test);
        std::cout << test << std::endl;
    }

    return 0;
}