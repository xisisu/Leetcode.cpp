//
// Created by Sisu on 11/10/2015.
//

/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the values in the list,
 * only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) { // 4 ms
        if (!head || !head->next) { return head; }

        // switch first round manually
        auto tmp = head->next;
        head->next = tmp->next;
        tmp->next = head;
        head = tmp;

        auto pre = tmp->next;
        while (pre->next && pre->next->next) {
            auto first = pre->next, second = first->next;
            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre = first;
        }

        return head;
    }

    ListNode* swapPairs_2(ListNOde* head) { // 4 ms
        if (!head || !head->next) { return head; }
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nxt = head->next;

        while (nxt) {
            cur->next = nxt->next;
            nxt->next = cur;
            if (pre) { pre->next = nxt; }
            else { head = nxt; }
            pre = cur;
            cur = pre->next;
            nxt = cur ? cur->next : NULL;
        }

        return head;
    }
};

int main() {
    Solution sol;
    auto a = constructListNode(std::vector<int> {1, 2, 3, 4});
    auto b = constructListNode(std::vector<int> {1, 2, 3});
    printListNode(sol.swapPairs(a));
    printListNode(sol.swapPairs(b));
    return 0;
}