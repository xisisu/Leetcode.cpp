//
// Created by Sisu on 3/3/2016.
//

/*
 * Given a binary tree, return all root-to-leaf paths.
 * For example, given the following binary tree:
 *
   1
 /   \
2     3
 \
  5
  All root-to-leaf paths are:
  ["1->2->5", "1->3"]
 */

#include <iostream>
#include <vector>
#include <string>
#include "Common.h"

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
public:
    void helper(TreeNode* root, std::vector<std::string>& res, std::string cur) { // 4 ms
        if (!root->left && !root->right) {
            res.push_back(cur);
            return;
        }

        if (root->left) {
            std::string left = cur + ("->" + to_string(root->left->val));
            helper(root->left, res, left);
        }
        if (root->right) {
            std::string right = cur + ("->" + to_string(root->right->val));
            helper(root->right, res, right);
        }
    }

    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> res;
        if (!root) { return res; }
        std::string cur = to_string(root->val);
        helper(root, res, cur);
        return res;
    }
};

int main () {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5};
    TreeNode* root = constructTreeByLevel(tests);

    auto res = sol.binaryTreePaths(root);
    for (auto const& val : res) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    return 0;
}