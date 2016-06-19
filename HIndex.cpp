//
// Created by xisisu on 6/17/16.
//

/*
 * Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute
 * the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at
 * least h citations each, and the other N − h papers have no more than h citations each."
 *
 * For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them
 * had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations
 * each and the remaining two with no more than 3 citations each, his h-index is 3.
 *
 * Note: If there are several possible values for h, the maximum one is taken as the h-index.
 *
 * Hint:
 *
 * An easy approach is to sort the array first.
 * What are the possible values of h-index?
 * A faster approach is to use extra space.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int> const& citations) { // 4 ms
        auto data = citations;
        std::sort(data.begin(), data.end());
        int res = citations.size();
        for (auto const& val : data) {
            if (val >= res) { break; }
            --res;
        }
        return res;
    }

    int hIndex2(std::vector<int> const& citations) { // 4 ms
        if (citations.empty()) { return 0; }
        int M = citations.size();
        std::vector<int> bucket(M+1, 0);
        for (auto const& val : citations) {
            auto idx = std::min(M, val);
            bucket[idx]++;
        }
        for (int i = M; i >= 1; --i) {
            if (bucket[i] >= i) { return i; }
            else { bucket[i-1] += bucket[i]; } // fall over to next bucket
        }
        return 0;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {0,0,0,0,0}
            , {3,0,6,1,5}
            , {1,1,1,1,1,1,1,1,1,1,1,1}
            , {1,1,1,1,1,1,1,1,1,1,1,1,1,2,2}
    };

    for (auto const& test : tests) {
        std::cout << "input : ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        std::cout << "output: " << sol.hIndex2(test) << std::endl << std::endl;
    }

    return 0;
}