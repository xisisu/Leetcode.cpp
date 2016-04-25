//
// Created by Sisu on 4/17/2016.
//

/*
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

#include "Common.h"
#include <iterator>
#include <unordered_map>

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
    TreeNode* helper(std::vector<int> const& pre, int pstart, int pend,
                     std::unordered_map<int, int>& in, int istart, int iend)
    {
        // [start, end]
        if (pstart > pend || istart > iend || pend > pre.size() || iend > in.size() || pstart < 0 || istart < 0) {
            return nullptr;
        }
        auto idx = in[pre[pstart]];
        auto res = new TreeNode(pre[pstart]);

        res->left  = helper(pre, pstart+1           , pstart+idx-istart, in, istart, idx-1);
        res->right = helper(pre, pstart+idx-istart+1, pend             , in, idx+1 , iend);
        return res;
    }

public:
    TreeNode* buildTree(std::vector<int> const& preorder, std::vector<int>& inorder) { // 20 ms
        if (preorder.size() != inorder.size() || preorder.empty()) { return nullptr; }
        std::unordered_map<int, int> reverseInOrder;
        for (int i = 0; i < inorder.size(); ++i) { reverseInOrder[inorder[i]] = i; }
        return helper(preorder, 0, preorder.size()-1, reverseInOrder, 0, inorder.size()-1);
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
            { {1,2,3}, {2,1,3} }
            , { {1,2,3}, {1,2,3} }
            , { {1,2,3}, {3,2,1} }
            , { {1,2}, {1,2} }
            , { {1,2,3}, {1,2,3} }
            , { {4,1,3,2,7,5,6}, {1,2,3,4,5,6,7} }
    };
    for (auto& test : tests) {
        std::cout << "pre order: ";
        std::copy(test.first.begin(), test.first.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        auto res = sol.buildTree(test.first, test.second);
        prettyPrintTree(res);
        std::cout << std::endl;
    }

    return 0;
}

