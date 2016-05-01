//
// Created by Sisu on 5/1/2016.
//

/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see
 * ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *    1            <---
 *  /   \
 * 2     3         <---
 *  \     \
 *   5     4       <---
 * You should return [1, 3, 4].
 */

#include "Common.h"
#include <iterator>

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
    std::vector<int> rightSideView(TreeNode *root) { // 4 ms
        if (!root) { return {}; }
        std::vector<int> res;
        std::queue<TreeNode *> q[2];
        int cur = 0;
        q[cur].push(root);
        while (!q[cur].empty()) {
            auto tmp = q[cur].front();
            q[cur].pop();
            if (q[cur].empty()) { res.push_back(tmp->val); } // add the right most view
            auto nxt = (cur+1)%2;
            if (tmp->left) { q[nxt].push(tmp->left); }
            if (tmp->right) { q[nxt].push(tmp->right); }
            if (q[cur].empty()) { cur = nxt; }
        }

        return res;
  }
};

int main() {
    Solution sol;
    std::vector<int> data = {0,1,2,3,4,5,6};
    auto root = constructTreeByLevel(data);
    prettyPrintTree(root);
    auto res = sol.rightSideView(root);
    std::cout << "res: ";
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    return 0;
}