//
// Created by Sisu on 3/19/2016.
//

/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 */

#include <iostream>
#include <algorithm>
#include <vector>


class Solution {
private:
    void next(std::string& cur) {
        /*
         * cur is guaranteed to be at least length 2
         * for example, 4752, next number is 5247.
         * start from end, find first decreasing number (4), then first next number (5)
         * swap (4) and (5), then sort after (5). we get 5247
         */
        auto start = cur.size()-2;
        while (cur.at(start) > cur.at(start+1) && start >= 0) { --start; }
        if (start == -1) { /* input is 321, return 123 */
            std::sort(cur.begin(), cur.end());
            return;
        }

        auto end = cur.size()-1; // we know from end to start+1, there are at least 1 element that is larger than start
        while (cur.at(end) < cur.at(start) && end > start) { --end; }

        std::swap(cur[start], cur[end]);
        std::sort(cur.begin() + start + 1, cur.end());
    }

public:
    std::string getPermutation(int n, int k) { // too slow, failed at n=9, k=14918
        /*
         *  n is between [1,9]
         */
        if (n == 1) { return "1"; }

        // avoid extremely large k
        int max = 1;
        for (int i = 1; i <= n; ++i) { max *= i; }
        k %= max;

        std::string base = "";
        for (int i = 1; i <= n; ++i) { base.append(1, '0' + i); }
        if (k == 0) { return base; }
        while (--k > 0) { next(base); }
        return base;
    }

public:
    std::string getPermutation2(int n, int k) { // 0 ms
        /*
         * n! = n * (n-1)!
         * 123     --------- start with 1
         * 132     --------- start with 1
         * 213     --------- start with 2
         * 231     --------- start with 2
         * 312     --------- start with 3
         * 321     --------- start with 3
         * rule: start with (k-1) / (n-1)!
         */
        std::vector<int> nums(n);
        int permCount = 1;
        for (auto i = 1; i <= n; ++i) { nums[i-1] = i; permCount *= i; }

        --k;
        std::string res;
        for (int i = n; i > 0; --i) {
            permCount /= i;
            int choosed = k / permCount;
            res.append(1, '0'+nums[choosed]);
            for (int j = choosed; j < i; ++j) { nums[j] = nums[j+1]; } // shift right
            k = k % permCount;
        }

        return res;
    }
};

int main() {
    Solution sol;
    for (int i = 1; i < 100; ++i) {
        std::cout << sol.getPermutation(9, i) << "," << sol.getPermutation2(9, i) << std::endl;
    }
    return 0;
}