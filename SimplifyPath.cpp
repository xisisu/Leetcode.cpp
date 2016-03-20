//
// Created by Sisu on 3/19/2016.
//

/*
 * Given an absolute path for a file (Unix-style), simplify it.
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

#include <vector>
#include <iostream>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string const& path) { // 8 ms
        if (path.empty() || path.at(0) != '/') { return ""; } // invalid input
        if (path.size() < 2) { return "/"; }

        std::stack<std::string> s;
        auto pre = path.find('/', 0); // should be init to 0
        do {
            auto cur = path.find('/', pre+1);
            if (cur == pre+1) { pre = cur; continue; } // "//", ignore

            auto tmp = (cur == std::string::npos) ? path.substr(pre+1) : path.substr(pre+1, cur-pre-1);
            if (tmp.compare("..") == 0) { if (!s.empty()) { s.pop(); } }
            else if (tmp.compare(".") == 0 || tmp.empty()) { ; } // ignore '.' and empty str
            else { s.push(tmp); }

            pre = cur;
        } while (pre != std::string::npos);

        std::string res = "";
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }

        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "/////////////"
            , "c"
            , "/////////home////////"
            , "/home/../../../../../"
            , "/a/./././././b/././c/././"
            , "/a/././././././b././././../../"
    };

    for (auto const& test : tests) {
        std::cout << test << ": " << sol.simplifyPath(test) << std::endl;
    }

    return 0;
}