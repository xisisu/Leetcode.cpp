//
// Created by Sisu on 4/17/2016.
//

/*
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

#include "Common.h"
#include <iterator>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) { // 28 ms
        if (!head) { return nullptr; }
        if (!head->next) { return new TreeNode(head->val); }
        auto slow = head, fast = head->next->next;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto second = slow->next;
        slow->next = nullptr;
        auto res  = new TreeNode(second->val);
        res->left  = sortedListToBST(head);
        res->right = sortedListToBST(second->next);
        return res;
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
        auto head = constructListNode(test);
        printListNode(head);

        auto res = sol.sortedListToBST(head);
        prettyPrintTree(res);
        std::cout << std::endl;
    }
    return 0;
}