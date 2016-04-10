//
// Created by Sisu on 4/9/2016.
//

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 */

#include <iostream>
#include <iterator>
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
    void helper(std::vector<std::vector<int>>& res, std::vector<int>& cur, TreeNode* root, int sum) {
        if (!root) { return; }
        if (!root->left && !root->right) {
            if (sum == root->val) {
                cur.push_back(root->val);
                res.push_back(cur);
                cur.pop_back();
            }
            return;
        }

        sum -= root->val;
        cur.push_back(root->val);
        if (root->left) { helper(res, cur, root->left, sum); }
        if (root->right) { helper(res, cur, root->right, sum); }
        cur.pop_back();
    }

public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) { // 20 ms
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        helper(res, cur, root, sum);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            {}
            , {"5", "4", "8", "11", "#", "13", "4", "7", "2", "#", "#", "5", "1"}
    };

    for (auto const& test: tests) {
        std::cout << "input is: " << std::endl;
        auto root = constructTreeBySymbol(test);
        prettyPrintTree(root);

        std::cout << "result: " << std::endl;
        auto res = sol.pathSum(root, 22);
        for (auto const& val : res) {
            std::copy(val.begin(), val.end(), std::ostream_iterator<int>(std::cout, ", "));
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}