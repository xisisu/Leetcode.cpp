//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right,
 * level by level from leaf to root).
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
#include <algorithm>

class Solution {
public:
    void helper(TreeNode* root, int level, std::vector<std::vector<int>>& res) {
        if (!root) { return; }
        while (res.size() < level) { res.push_back(std::vector<int>()); } // pushing empty level
        res[level-1].push_back(root->val);
        helper(root->left, level+1, res);
        helper(root->right, level+1, res);
    }

    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (!root) { return res; }
        helper(root, 1, res);
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5,6,7,8};
    auto root = constructTreeByLevel(tests);
    printFullTree(root);

    auto res = sol.levelOrderBottom(root);
    for (const auto & row : res) {
        for (const auto & val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}