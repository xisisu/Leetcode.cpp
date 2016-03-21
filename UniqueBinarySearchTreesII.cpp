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
#include <vector>
#include <map>
#include "Common.h" // for TreeNode

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    std::vector<TreeNode*> helper(int s, int e) { // 24 ms
        std::vector<TreeNode*> res;
        if (s > e) { res.push_back(nullptr); return res; }
        if (s == e) { res.push_back(new TreeNode(s)); return res; }

        for (int i = s; i <= e; ++i) {
            auto left = helper(s, i-1);
            auto right = helper(i+1, e);

            for (int x = 0; x < left.size(); ++x) {
                for (int y = 0; y < right.size(); ++y) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left[x];
                    cur->right = right[y];
                    res.push_back(cur);
                }
            }
        }

        return res;
    }

public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) { return std::vector<TreeNode*>(); }
        return helper(1, n);
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ", " << sol.generateTrees(i).size() << std::endl;
    }
    return 0;
}