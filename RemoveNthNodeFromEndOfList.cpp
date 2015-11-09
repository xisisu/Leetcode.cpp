//
// Created by Sisu on 11/8/2015.
//

/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include "Common.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { // 4 ms
        auto first = head, second = head;
        for (int i = 0; i < n-1; ++i) {
            if (!first) { return head; } // if length is not enough
            first = first->next;
        }
        first = first->next;
        if (!first) { return head->next; } // if head is the one to remove

        first = first->next; // moved n+1 for first, so second always points to (n+1)th to last
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;

        return head;
    }
};

int main() {
    Solution sol;
    auto a = constructListNode(std::vector<int> {1, 2, 3, 4, 5});
    printListNode(a);
    auto b = sol.removeNthFromEnd(a, 2);
    printListNode(b);
    return 0;
}