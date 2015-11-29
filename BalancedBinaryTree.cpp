//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the
 * two subtrees of every node never differ by more than 1.
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
#include <unordered_map>
#include <cstdlib>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) { return 0; }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) { // 16 ms
        if (!root) { return true; }
        auto left = maxDepth(root->left), right = maxDepth(root->right);
        if (std::abs(left-right) > 1) { return false; }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    // dynamic programming
    bool isBalanced_2(TreeNode* root) { // 20 ms
        std::unordered_map<TreeNode*, int> table;
        return isBalanced_2(root, table);
    }

    bool isBalanced_2(TreeNode* root, std::unordered_map<TreeNode*, int>& table) {
        if (!root) { return true; }
        auto left = depth(root->left, table);
        auto right =depth(root->right, table);
        if (std::abs(left-right) > 1) { return false; }
        return isBalanced_2(root->left, table) && isBalanced_2(root->right, table);
    }

    int depth(TreeNode* root, std::unordered_map<TreeNode*, int>& table) {
        if (!root) { return 0; }
        if (table.count(root)) { return table[root]; }
        return std::max(depth(root->left, table), depth(root->right, table)) + 1;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,2,3,4,5,6,7,8,9};
    auto root = constructTreeByLevel(tests);
    printFullTree(root);
    std::cout << sol.isBalanced(root) << std::endl;
    return 0;
}