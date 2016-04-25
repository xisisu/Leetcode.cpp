//
// Created by Sisu on 4/24/2016.
//

/*
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
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
    TreeNode* helper(std::vector<int> const& post, int pstart, int pend,
                     std::unordered_map<int, int>& in, int istart, int iend)
    {
        // [start, end]
        if (pstart > pend || istart > iend || pend > post.size() || iend > in.size() || pstart < 0 || istart < 0) {
            return nullptr;
        }
        auto idx = in[post[pend]];
        auto res = new TreeNode(post[pend]);

        res->left  = helper(post, pstart           , pstart+idx-istart-1, in, istart, idx-1);
        res->right = helper(post, pstart+idx-istart, pend-1             , in, idx+1 , iend);
        return res;
    }

public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) { // 20 ms
        if (inorder.size() != inorder.size() || inorder.empty()) { return nullptr; }
        std::unordered_map<int, int> reverseInOrder;
        for (int i = 0; i < inorder.size(); ++i) { reverseInOrder[inorder[i]] = i; }
        return helper(postorder, 0, postorder.size()-1, reverseInOrder, 0, inorder.size()-1);
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::vector<int>, std::vector<int>>> tests = {
              { {2,1,3}, {2,3,1} }
            , { {3,2,1}, {3,2,1} }
            , { {1,2,3}, {3,2,1} }
    };
    for (auto& test : tests) {
        std::cout << "in order: ";
        std::copy(test.first.begin(), test.first.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        auto res = sol.buildTree(test.first, test.second);
        prettyPrintTree(res);
        std::cout << std::endl;
    }

    return 0;
}