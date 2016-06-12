//
// Created by xisisu on 6/12/16.
//

/*
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How
 * would you optimize the kthSmallest routine?
 *
 * Hint:
 *
 * Try to utilize the property of a BST.
 * What if you could modify the BST node's structure?
 * The optimal runtime complexity is O(height of BST).
 */

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
    int kthSmallest(TreeNode* root, int k) { // 24 ms
        /*
         * if it is a fully tree, can reduce to O(log n)
         * otherwise, use in-order traversal to find the kth one
         */
        if (k < 1) { return INT32_MIN; }
        std::vector<int> res;
        std::stack<TreeNode *> s;
        auto cur = root;

        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                --k;
                if (k == 0) { return cur->val; }
                cur = cur->right;
            }
        }

        return INT32_MIN;
    }
};

int main() {
    Solution sol;
    auto root = constructTreeByLevel({4,2,6,1,3,5,7});
    for (int i = 1; i <= 7; ++i) {
        std::cout << i << ", " << sol.kthSmallest(root, i) << std::endl;
    }
    return 0;
}