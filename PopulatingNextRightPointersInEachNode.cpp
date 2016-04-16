//
// Created by Sisu on 4/15/2016.
//

/*
 * Given a binary tree
 *
 *     struct TreeLinkNode {
 *       TreeLinkNode *left;
 *       TreeLinkNode *right;
 *       TreeLinkNode *next;
 *     }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should
 * be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two
 * children).
 * For example,
 * Given the following perfect binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \  / \
 *     4  5  6  7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \  / \
 *     4->5->6->7 -> NULL
 */

#include "Common.h"
#include <queue>

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) { // 28 ms
        /*
         * use nullptr as a separator between levels
         */
        if (!root) { return; }
        std::queue<TreeLinkNode*> queue;
        queue.push(root);
        queue.push(nullptr);
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            if (!cur) {
                if (queue.empty()) { return; }
                else { queue.push(nullptr); continue; }
            }
            cur->next = queue.front();
            if (cur->left) { queue.push(cur->left); }
            if (cur->right) { queue.push(cur->right); }
        }
    }
};