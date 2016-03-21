//
// Created by Sisu on 3/20/2016.
//

/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *   1         3     3      2      1
 *    \       /     /      / \      \
 *     3     2     1      1   3      2
 *    /     /       \                 \
 *   2     1         2                 3
 */

#include <iostream>
#include <map>

class Solution {
private:
    std::map<int, long long> _map; // cache to speed up

public:
    int numTrees(int n) { // 0 ms
        if (n < 3) { return n; }
        if (_map.find(n) != _map.end()) { return _map[n]; }

        long long res = 0;
        for (int root = 1; root <= n; ++root) { // take turns to be root
            long long left  = numTrees(root-1);
            long long right = numTrees(n-root);
            if (left == 0 || right == 0) { res += (left+right); }
            else { res += left * right; }
        }
        _map[n] = res;

        return _map[n];
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ", " << sol.numTrees(i) << std::endl;
    }

    return 0;
}