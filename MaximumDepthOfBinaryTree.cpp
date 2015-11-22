//
// Created by Sisu on 11/22/2015.
//

/*
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "common.h"
#include <vector>

class Solution {
public:
    int maxDepth(TreeNode* root) { // 8 ms
        return root ? std::max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests;
    for (int i = 0; i < 100; ++i) { tests.push_back(i); }
    auto root = constructTreeByLevel(tests);
    printFullTree(root);

    std::cout << sol.maxDepth(root) << std::endl;
    return 0;
}