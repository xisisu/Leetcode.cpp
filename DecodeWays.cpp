//
// Created by Sisu on 4/2/2016.
//

/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 *         Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */

#include <iostream>
#include <vector>


class Solution {
public:
    int numDecodings(std::string const& s) { // 4 ms
        /*
         * Typical dp problem
         * Consider the following example:
         * "" -> 0
         * "1" -> 1
         * "14" -> 1,4 or 14, which is 2
         * "114" -> 1,1,4 or 1,14 or 11, 4, which is dp[i+1] + dp[i+2]
         *
         * Note special cases when s[i] = "0", this time returns 0
         */
        auto N = s.size();
        if (N == 0) { return 0; }
        std::vector<int> dp(N+1, 0);
        dp[N] = 1;

        for (int i = N-1; i >= 0; --i) {
            if (s[i] == '0') { dp[i] = 0; }
            else { dp[i] = dp[i+1]; }

            if ( (i != N-1) && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) { dp[i] += dp[i+2]; }
        }

        return dp[0];
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "1"
            , "26"
            , "0"
            , "00"
            , "10"
            , "12"
            , "1234"
            , "101"
    };

    for (auto const& test : tests) {
        std::cout << test << ", " << sol.numDecodings(test) << std::endl;
    }

    return 0;
}