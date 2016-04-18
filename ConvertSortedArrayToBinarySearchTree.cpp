//
// Created by Sisu on 4/17/2016.
//

/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
private:
    TreeNode* sortedArrayToBST(std::vector<int> const& nums, int start, int end) {
        // construct tree from [start, end)
        if (start >= end) { return nullptr; }
        if (start + 1 == end) { return new TreeNode(nums[start]); }
        int mid = (start+end)/2;
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = sortedArrayToBST(nums, start, mid);
        res->right = sortedArrayToBST(nums, mid+1, end);
        return res;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int> const& nums) { // 32 ms
        return sortedArrayToBST(nums, 0, nums.size());
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1,2}
            , {1,2,3}
            , {1,2,3,4,5,6,7,8,9,10}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        auto res = sol.sortedArrayToBST(test);
        prettyPrintTree(res);
        std::cout << std::endl;
    }
    return 0;
}