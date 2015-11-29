//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    /*
     * take only alphanumeric characters out of a string
     */
    std::string trim(std::string s) { // 16 ms
        std::string res = "";
        for (auto c : s) {
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
                res.append(1, c);
            } else if (c >= 'A' && c <= 'Z') {
                res.append(1, c-'A'+'a'); // convert to lower case
            }
        }
        return res;
    }

    bool isPalindrome(std::string s) {
        auto t = trim(s);
        auto r = t;
        std::reverse(t.begin(), t.end());
        return t == r;
    }

    bool valid(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z');
    }

    bool isPalindrome_2(std::string s) { // 12 ms
        int start = 0, end = s.size()-1;
        while (start < end) {
            while (start < end && !valid(s[start])) { ++start; }
            while (start < end && !valid(s[end])) { --end; }

            if (tolower(s[start]) != tolower(s[end])) { return false; }
            ++start;
            --end;
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {"", "abcddcba", "a    11a"};
    for (const auto &item : tests) {
        std::cout << item << ", " << sol.isPalindrome(item) << std::endl;
    }
    return 0;
}