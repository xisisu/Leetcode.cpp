//
// Created by Sisu on 3/20/2016.
//

/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
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
    /* note to use long long here, since a single node with INT32_MIN should still return true */
    bool helper(TreeNode* root, long long left, long long right) {
        if (!root) { return true; }
        if ((long long)root->val <= left || (long long)root->val >= right) { return false; }

        return helper(root->left, left, root->val) && helper(root->right, root->val, right);
    }

public:
    bool isValidBST(TreeNode* root) { // 16 ms
        return helper(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1,2,3}
            , {4,2,6,1,3,5,7}
            , {std::numeric_limits<int>::min()}
    };

    std::ostream_iterator<int> out(std::cout, ", ");
    for (auto& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), out);
        auto root = constructTreeByLevel(test);
        std::cout << std::endl << "result: " << sol.isValidBST(root) << std::endl << std::endl;
    }

    return 0;
}