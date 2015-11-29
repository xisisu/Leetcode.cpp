//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree is symmetric:
 *
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) { return true; }
        if (!left || !right) { return false; }
        if (left->val != right->val) { return false; }
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) { // 4 ms
        if (!root) { return true; }
        return isSymmetric(root->left, root->right);
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1, 2, 2, 3, 3, 3, 3};
    auto root = constructTreeByLevel(tests);
    std::cout << sol.isSymmetric(root) << std::endl;
    return 0;
}