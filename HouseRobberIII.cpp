//
// Created by xisisu on 6/26/16.
//

/*
 * The thief has found himself a new place for his thievery again. There is only one entrance to this area, called
 * the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized
 * that "all houses in this place forms a binary tree". It will automatically contact the police if two
 * directly-linked houses were broken into on the same night.
 *
 * Determine the maximum amount of money the thief can rob tonight without alerting the police.
 *
 * Example 1:
 *      3
 *     / \
 *    2   3
 *     \   \
 *      3   1
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:
 *      3
 *     / \
 *    4   5
 *   / \   \
 *  1   3   1
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 */


#include <unordered_map>
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
private:
    int helper(TreeNode* root, std::unordered_map<TreeNode*, int>& map) {
        if (!root) { return 0; }
        if (map.count(root)) { return map[root]; }
        if (!root->left && !root->right) {
            map[root] = root->val;
        } else {
            int val1 = root->val;
            if (root->left)  { val1 += helper(root->left->left, map) + helper(root->left->right, map); }
            if (root->right) { val1 += helper(root->right->left, map) + helper(root->right->right, map); }
            int val2 = helper(root->left, map) + helper(root->right, map);
            map[root] = std::max(val1, val2);
        }
        return map[root];
    }

public:
    int rob(TreeNode* root) { // 28 ms
        std::unordered_map<TreeNode*, int> map;
        return helper(root, map);
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::string>> tests = {
            {"3", "2", "3", "#", "3", "#", "1"}
            , {"3", "4", "5", "1", "3", "#", "1"}
    };

    for (auto const& test : tests) {
        auto root = constructTreeBySymbol(test);
        prettyPrintTree(root);
        std::cout << sol.rob(root) << std::endl << std::endl;
    }

    return 0;
}