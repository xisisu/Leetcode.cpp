//
// Created by Sisu on 11/10/2015.
//

/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together
 * the nodes of the first two lists.
 */

#include <iostream>
#include "Common.h"
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { // 12 ms
        if (!l1) { return l2; }
        if (!l2) { return l1; }

        ListNode * res = l1->val < l2->val ? l1 : l2;
        if (l1->val < l2->val) { l1 = l1->next; }
        else { l2 = l2->next; }

        ListNode * cur = res;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1) { cur->next = l1; }
        if (l2) { cur->next = l2; }

        return res;
    }
};

int main() {
    Solution sol;
    auto a = constructListNode(std::vector<int> {1, 2, 3, 4, 5});
    auto b = constructListNode(std::vector<int> {});
    auto c = constructListNode(std::vector<int> {1, 2, 3});

    printListNode(sol.mergeTwoLists(a, b));
    printListNode(sol.mergeTwoLists(a, c));

    return 0;
}