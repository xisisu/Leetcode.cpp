//
// Created by Sisu on 4/16/2016.
//

/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
 */

#include "Common.h"
#include <iterator>
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
    void preorderTraversal(TreeNode* root, std::vector<int>& res) {
        if (!root) { return; }
        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }

public:
    std::vector<int> preorderTraversal(TreeNode* root) { // 0 ms
        std::vector<int> res;
        preorderTraversal(root, res);
        return res;
    }

public:
    std::vector<int> preorderTraversal2(TreeNode* root) { // 0 ms
        std::vector<int> res;
        TreeNode* cur = root;
        std::stack<TreeNode*> s;

        while (cur || !s.empty()) {
            if (cur) {
                res.push_back(cur->val);
                if (cur->right) { s.push(cur->right); }
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
                {"#"}
                , {"1", "4", "2", "3"}
                , {"1", "#", "2", "3"}
    };

    for (auto const& test : tests) {
        std::cout << "input tree: " << std::endl;
        auto root = constructTreeBySymbol(test);
        prettyPrintTree(root);

        auto res = sol.preorderTraversal(root);
        std::cout << "res: ";
        std::copy(res.begin(), res.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    }

    return 0;
}