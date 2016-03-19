//
// Created by Sisu on 3/19/2016.
//

/*
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 * Calling next() will return the next smallest number in the BST.
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */

#include <iostream>
#include <vector>
#include <stack>
#include "Common.h" // for TreeNode

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator { // 28 ms
private:
    std::stack<TreeNode*> s;

public:
    BSTIterator(TreeNode *root) {
        while (root) { s.push(root); root = root->left; }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        auto cur = s.top();
        s.pop();
        if (cur->right) {
            auto tmp = cur->right;
            while (tmp) { s.push(tmp); tmp = tmp->left; }
        }
        return cur->val;
    }
};

int main() {
    std::vector<int> input = {4,2,6,1,3,5,7};
    auto root = constructTreeByLevel(input);
    BSTIterator it(root);
    while (it.hasNext()) {
        std::cout << it.next() << ", ";
    }
    return 0;
}