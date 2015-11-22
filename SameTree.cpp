//
// Created by Sisu on 11/22/2015.
//

/*
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
#include <vector>
#include <iostream>

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // 0 ms
        if (!p && !q) { return true; }
        else if ( (p && !q) || (!p && q) ) { return false; }
        else if (p->val != q->val) { return false; }
        else { return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); }
    }
};

int main() {
    Solution sol;
    std::vector<int> a = {1,2,3,4};
    std::vector<int> b = a;
    std::vector<int> c = {1,2,3,4,5};

    auto atree = constructTreeByLevel(a);
    auto btree = constructTreeByLevel(b);
    auto ctree = constructTreeByLevel(c);

    std::cout << sol.isSameTree(atree, btree) << std::endl;
    std::cout << sol.isSameTree(btree, ctree) << std::endl;

    return 0;
}