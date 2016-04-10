//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values
 * along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) { // 12 ms
        if (!root) { return false; }
        if (!root->left && !root->right) { return root->val == sum ? true : false; }
        sum -= root->val;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5,6,7};
    auto root= constructTreeByLevel(tests);
    printFullTree(root);
    std::cout << sol.hasPathSum(root, 22) << std::endl;
    return 0;
}