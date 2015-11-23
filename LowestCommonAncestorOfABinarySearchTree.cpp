//
// Created by Sisu on 11/22/2015.
//

/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v
 * and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a
 * descendant of itself).”
 *
        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2,
 * since a node can be a descendant of itself according to the LCA definition.
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
#include "common.h"
#include <vector>

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // 40 ms
        if (root == q || root == p) { return root; }
        else if (root->val < p->val && root->val < q->val) { return lowestCommonAncestor(root->right, p, q); }
        else if (root->val > p->val && root->val > q->val) { return lowestCommonAncestor(root->left, p, q); }
        else { return root; }
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {6,2,8,0,4,7,9};
    auto root = constructTreeByLevel(tests);
    printFullTree(root);
    auto a = root->left->left;
    auto b = root->left;
    std::cout << sol.lowestCommonAncestor(root, a, b)->val << std::endl;
    return 0;

}