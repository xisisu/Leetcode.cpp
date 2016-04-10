//
// Created by Sisu on 4/9/2016.
//

/*
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 *
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order
 * traversal.
 */

#include <iostream>
#include <stack>
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
    void flatten2(TreeNode* root) { // 8 ms
        std::stack<TreeNode*> s;
        auto cur = root;
        TreeNode* pre = nullptr;

        while (cur || !s.empty()) {
            if (cur) {
                if (pre) { pre->left = nullptr; pre->right = cur; }
                pre = cur;

                if (cur->right) { s.push(cur->right); }
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
            }
        }
    }

public:
    void flatten(TreeNode* root) { // 12 ms
        if (!root) { return; }
        if (root->left) { flatten(root->left); }
        if (root->right) { flatten(root->right); }

        if (root->left) {
            auto tempRight = root->right;
            root->right = root->left;
            root->left = nullptr;

            auto cur = root->right;
            while (cur->right) { cur = cur->right; }
            cur->right = tempRight;
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            {}
            , {"1", "2", "5", "3", "4", "#", "6"}
    };

    for (auto& test : tests) {
        std::cout << "before: " << std::endl;
        auto root = constructTreeBySymbol(test);
        prettyPrintTree(root);

        std::cout << "after: " << std::endl;
        sol.flatten(root);
        prettyPrintTree(root);

        std::cout << "before: " << std::endl;
        root = constructTreeBySymbol(test);
        prettyPrintTree(root);

        std::cout << "after: " << std::endl;
        sol.flatten2(root);
        prettyPrintTree(root);

        std::cout << std::endl;
    }

    return 0;
}