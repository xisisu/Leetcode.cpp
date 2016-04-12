//
// Created by Sisu on 4/11/2016.
//

/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *    / \
 *   2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
 */

#include "Common.h"
#include <iostream>
#include <stack>

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
    void helper(TreeNode* root, int& sum, int cur) {
        if (!root) { return; }
        int nxt = cur*10 + root->val;
        if (!root->left && !root->right) { sum += nxt; return; }
        if (root->left)  { helper(root->left, sum, nxt); }
        if (root->right) { helper(root->right, sum, nxt); }
    }

public:
    int sumNumbers(TreeNode* root) { // 4 ms
        /*
         * do not consider overflow problem
         * simple pre-order traversal
         */
        int sum = 0;
        helper(root, sum, 0);
        return sum;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            { { } }
            , { {"1", "2", "3"} }
    };

    for (auto const& test : tests) {
        auto root = constructTreeBySymbol(test);
        std::cout << "input: " << std::endl;
        prettyPrintTree(root);
        std::cout << "sum: " << sol.sumNumbers(root) << std::endl << std::endl;
    }

    return 0;
}