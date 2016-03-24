//
// Created by Sisu on 3/23/2016.
//

/*
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
 */

#include <iostream>
#include <vector>
#include <stack>
#include <set>
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
    void helper(TreeNode* root, std::vector<int>& res) {
        if (!root) { return; }
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }

public:
    std::vector<int> inorderTraversal(TreeNode* root) { // 3 ms
        std::vector<int> res;
        helper(root, res);
        return res;
    }

public:
    std::vector<int> inorderTraversal2(TreeNode* root) { // 0 ms
        std::vector<int> res;
        std::stack<TreeNode*> s;
        auto cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> data = {1,2,3,4,5,6};
    auto root = constructTreeByLevel(data);
    Solution sol;

    for (auto const& val : sol.inorderTraversal(root)) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    for (auto const& val : sol.inorderTraversal2(root)) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    return 0;
}