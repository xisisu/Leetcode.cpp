//
// Created by Sisu on 4/12/2016.
//

/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 *
 *   [
 *     ["aa","b"],
 *     ["a","a","b"]
 *   ]
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
private:
    bool valid(std::string const& s, int start, int len) {
        if (len <= 1) { return true; }
        int end = start + len - 1;
        while (start < end && s[start] == s[end]) { ++start; --end; }
        return end <= start;
    }

private:
    void helper(std::string const & s, std::vector<std::vector<std::string>>& res, std::vector<std::string> cur, int idx) {
        if (idx == s.size()) { res.push_back(cur); return; }

        for (int len = 1; len <= s.size()-idx; ++len) {
            if (valid(s, idx, len)) {
                cur.push_back(s.substr(idx, len));
                helper(s, res, cur, idx+len);
                cur.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string const& s) { // 36 ms
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> cur;
        helper(s, res, cur, 0);
        return res;
    }

private:
    void helper(std::string const & s, std::vector<std::vector<std::string>>& res,
                 std::vector<std::string>& cur, int idx, std::vector<std::vector<bool>>& dp)
    {
        if (idx == s.size()) { res.push_back(cur); return; }

        for (int len = 1; len <= s.size()-idx; ++len) {
            if (dp[idx][idx+len-1]) {
                cur.push_back(s.substr(idx, len));
                helper(s, res, cur, idx+len, dp);
                cur.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition2(std::string const& s) { // 16 ms
        /*
         * pre-build the dp map for speeding up
         */
        std::vector<std::vector<std::string>> res;
        if (s.empty()) { return res; }
        auto N = s.size();
        std::vector<std::vector<bool>> dp(N, std::vector<bool>(N, false));
        for (int len = 1; len <= N; ++len) {
            for (int start = 0; start <= N-len; ++start) {
                auto end = start + len - 1;
                dp[start][end] = (s[start] == s[end]) && (start+1 >= end-1 || dp[start+1][end-1]);
            }
        }

        std::vector<std::string> cur;
        helper(s, res, cur, 0, dp);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "a"
            , "aa"
            , "ab"
            , "aab"
    };

    for (auto const& test : tests) {
        std::cout << "input: " << test << std::endl;
        auto res = sol.partition2(test);
        for (auto const & row : res) {
            std::copy(row.begin(), row.end(), std::ostream_iterator<std::string>(std::cout, ","));
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}