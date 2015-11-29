//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

class Solution {
public:
    int minDepth(TreeNode* root) { // 12 ms
        if (!root) { return 0; }
        else if (!root->left && !root->right) { return 1; }
        else if (!root->left || !root->right) {
            if (root->left) { return minDepth(root->left) + 1; }
            else { return minDepth(root->right) + 1; }
        }
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5,6,7};
    auto root = constructTreeByLevel(tests);
    printFullTree(root);
    std::cout << sol.minDepth(root) << std::endl;
    return 0;
}