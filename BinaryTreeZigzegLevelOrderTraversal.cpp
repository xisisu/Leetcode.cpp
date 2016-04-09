//
// Created by Sisu on 4/9/2016.
//

/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then
 * right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 */

#include <iostream>
#include <iterator>
#include <algorithm>
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) { // 4 ms
        std::vector<std::vector<int>> res;
        if (!root) { return res; }

        std::queue<TreeNode*> queue[2];
        int cur = 0;
        queue[cur].push(root);
        std::vector<int> x;
        while (!queue[cur].empty()) {
            int nxt = (cur+1) % 2;

            auto tmp = queue[cur].front();
            queue[cur].pop();
            x.push_back(tmp->val);
            if (tmp->left) { queue[nxt].push(tmp->left); }
            if (tmp->right) { queue[nxt].push(tmp->right); }

            if (queue[cur].empty()) {
                if (cur == 1) { std::reverse(x.begin(), x.end()); }
                res.push_back(x);
                x.clear();
                cur = nxt;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            {}
            , { "1" }
            , { "3", "9", "20", "#", "#", "15", "7" }
    };

    for (auto const& test : tests) {
        std::cout << std::endl << "input: " << std::endl;
        auto root = constructTreeBySymbol(test);
        prettyPrintTree(root);

        std::cout << "result: " << std::endl;
        auto res = sol.zigzagLevelOrder(root);
        for (auto const& row : res) {
            std::copy(row.begin(), row.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << std::endl;
        }
    }
    return 0;
}

