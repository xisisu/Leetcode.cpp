//
// Created by xisisu on 5/21/16.
//

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as
 * the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______3______
 *        /              \
 *     ___5__          ___1__
 *    /      \        /      \
 *    6      _2       0       8
 *          /  \
 *          7   4
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5,
 * since a node can be a descendant of itself according to the LCA definition.
 */

#include "Common.h"
#include <unordered_set>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // 36 ms
        if (!root || !p || !q) { return nullptr; }
        if (q == p) { return p; } // if equal, return
        /*
         * store the path from root to first node, then when found second node, populate path until find
         */
        auto foundFirst = false;
        TreeNode* firstNode = nullptr;
        std::stack<TreeNode*> stack;
        std::unordered_set<TreeNode*> set;
        TreeNode* pre = nullptr;
        stack.push(root);

        while (!stack.empty()) {
            auto cur = stack.top();
            if (!pre || pre->left == cur || pre->right == cur) {
                if (cur->left) { stack.push(cur->left); }
                else if (cur->right) { stack.push(cur->right); }
            } else if (cur->left == pre) {
                if (cur->right) { stack.push(cur->right); }
            } else {
                if (cur == p || cur == q) {
                    if (!foundFirst) { // this is the first node, store its path
                        auto tmp = stack;
                        while (!tmp.empty()) { set.insert(tmp.top()); tmp.pop(); }
                        foundFirst = true;
                        firstNode = cur;
                    } else { // this is the second node, populate path until find the one
                        if (cur == firstNode) { continue; }
                        while (!stack.empty()) {
                            if (set.count(stack.top())) { return stack.top(); }
                            stack.pop();
                        }
                    }
                }
                stack.pop();
            }
            pre = cur;
        }

        return nullptr;
    }

public:
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) { // 24 ms
        /*
         * Simple and cleaver!!!
         */
        if (!root || root == q || root == p) { return root; }
        auto left  = lowestCommonAncestor2(root->left , p, q);
        auto right = lowestCommonAncestor2(root->right, p, q);
        if (left && right) { return root; }
        return left ? left : right;
    }
};

int main() {
    Solution sol;
    std::vector<int> data = {1,2,3,4,5,6,7,8,9,10};
    auto root = constructTreeByLevel(data);
    prettyPrintTree(root);

    auto res = sol.lowestCommonAncestor(root, root->left, root->right);
    std::cout << res->val << std::endl;

    res = sol.lowestCommonAncestor(root, root->left, root->left->left);
    std::cout << res->val << std::endl;

    return 0;
}