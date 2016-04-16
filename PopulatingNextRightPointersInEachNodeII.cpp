//
// Created by Sisu on 4/15/2016.
//

/*
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *          1
 *        /  \
 *       2    3
 *      / \    \
 *     4   5    7
 * After calling your function, the tree should look like:
 *          1 -> NULL
 *        /  \
 *       2 -> 3 -> NULL
 *      / \    \
 *     4-> 5 -> 7 -> NULL
 */

#include "Common.h"

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
    void connect(TreeLinkNode *root) { // 40 ms
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