//
// Created by Sisu on 11/22/2015.
//

/*
 * Invert a binary tree.
 *         4
 *      /   \
 *     2     7
 *   / \   / \
 * 1   3 6   9
 * to
 *        4
 *      /   \
 *     7     2
 *   / \   / \
 * 9   6 3   1
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

#include <iostream>
#include <vector>
#include "common.h"
#include <queue>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { // 4 ms
        if (!root) { return nullptr; }
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();

            auto tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;

            if (cur->left) queue.push(cur->left);
            if (cur->right) queue.push(cur->right);
        }

        return root;
    }

    TreeNode* invertTree_2(TreeNode* root) { // 0 ms
        if (!root) { return nullptr; }
        auto tmp = root->left;
        root->left = invertTree_2(root->right);
        root->right = invertTree_2(tmp);
        return root;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests;
    for (int i = 0; i < 100; ++i) { tests.push_back(i); }
    auto root = constructTreeByLevel(tests);
    printFullTree(root);

    auto res = sol.invertTree_2(root);
    printFullTree(res);

    return 0;
}