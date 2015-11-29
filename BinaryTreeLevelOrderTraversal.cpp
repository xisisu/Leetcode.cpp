//
// Created by Sisu on 11/29/2015.
//

/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) { // 8 ms
        std::vector<std::vector<int>> res;
        if (!root) { return res; }
        std::queue<TreeNode*> queue;
        queue.push(root);
        queue.push(nullptr); // use nullptr to represent end of the level
        std::vector<int> level;
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            if (!cur && queue.empty()) { // queue is empty, and we got the results
                res.push_back(level);
                break;
            }
            if (!cur) { // we have finished one level, push level to res and reset
                res.push_back(level);
                level.clear();
                queue.push(nullptr);
            } else {
                if (cur->left) { queue.push(cur->left); }
                if (cur->right) { queue.push(cur->right); }
                level.push_back(cur->val);
            }
        }
        return res;
    }

    std::vector<std::vector<int>> levelOrder_2(TreeNode* root) { // 4 ms
        std::vector<std::vector<int>> res;
        if (!root) { return res; }

        std::queue<TreeNode*> q[2];
        int which = 0;
        q[which].push(root);

        std::vector<int> x;
        while (!q[which].empty()) {
            auto cur = q[which].front();
            q[which].pop();
            x.push_back(cur->val);

            auto nxt = (which+1) % 2;
            if (cur->left) { q[nxt].push(cur->left); }
            if (cur->right) { q[nxt].push(cur->right); }

            if (q[which].empty()) {
                res.push_back(x);
                x.clear();
                which = nxt;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5,6,7,8};
    auto root = constructTreeByLevel(tests);
    printFullTree(root);

    auto res = sol.levelOrder(root);
    for (const auto & row : res) {
        for (const auto & val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}