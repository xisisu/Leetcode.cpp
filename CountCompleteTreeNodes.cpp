//
// Created by xisisu on 5/19/16.
//

/*
 * Given a complete binary tree, count the number of nodes.
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last
 * level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */

#include "Common.h"
#include <stack>
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
public:
    int countNodes(TreeNode* root) { // too slow
        int  res = 0;
        auto cur = root;
        std::stack<TreeNode*> s;
        while (cur || !s.empty()) {
            if (cur) {
                ++res;
                if (cur->right) { s.push(cur->right); }
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
            }
        }
        return res;
    }

private:
    bool checkbit(long val, long n) {
        // check whether n'th bit is 1 (from right to left, starting from 1)
        long cur = 0x01;
        cur <<= (n-1);
        return val & cur;
    }

private:
    bool find(TreeNode* root, long val, long height) {
        auto cur = root;
        while (height > 0) {
            if (!cur) { return false; }
            if (checkbit(val, height)) { cur = cur->right; }
            else { cur = cur->left; }
            --height;
        }
        return cur != nullptr;
    }

public:
    int countNodes2(TreeNode* root) { // 233 ms
        if (!root) { return 0; }

        /*
         * similar to binary search
         */
        // find the height of the tree
        auto cur = root;
        int height = 0;
        while (cur) {
            cur = cur->left;
            ++height;
        }
        --height;

        // binary search
        long low  = 0;
        long high = (1 << height)-1;
        while (low <= high) {
            auto mid = low + (high - low) / 2;
            if (find(root, mid, height)) { low = mid+1; }
            else { high = mid-1; }
        }

        int res = (1 << height)-1;
        return res + low;
    }

public:
    int countNodes3(TreeNode* root, int leftHeight, int rightHeight) { // 120 ms
        if (!root) { return 0; }
        /*
         * if height == -1, means we need to count them
         */
        int left = leftHeight;
        if (-1 == left) {
            auto cur = root->left;
            left = 0;
            while (cur) { cur = cur->left; ++left; }
        }
        int right = rightHeight;
        if (-1 == right) {
            auto cur = root->right;
            right = 0;
            while (cur) { cur = cur->right; ++right; }
        }

        if (left == right) { return (1 << (left+1))-1; }
        else { return countNodes3(root->left, left-1, -1) + countNodes3(root->right, -1, right-1) + 1; }
    }


public:
    int countNodes3(TreeNode* root) {
        // check left-most and right-most to see if it is full tree
        return countNodes3(root, -1, -1);
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {1,2,3,4,5,6,7,8,9,10}
            , {}
            , {1}
            , {1,2,3,4,5,6,7}
    };

    for (auto const& test : tests) {
        auto root = constructTreeByLevel(test);
        std::cout << "input: ";
        std::copy(test.begin(), test.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
        std::cout << sol.countNodes(root) << ", " << sol.countNodes2(root) << ", " << sol.countNodes3(root) << std::endl;
    }

    return 0;
}