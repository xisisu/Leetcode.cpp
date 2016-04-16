//
// Created by Sisu on 4/15/2016.
//

/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Note: Do not modify the linked list.
 * Follow up:
 * Can you solve it without using extra space?
 */

#include "Common.h"
#include <unordered_set>

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
    ListNode *detectCycle(ListNode *head) { // 28 ms
        std::unordered_set<ListNode*> seen;
        while (head) {
            if (seen.count(head)) { return head; }
            seen.insert(head);
            head = head->next;
        }
        return nullptr;
    }

    ListNode *detectCycle2(ListNode *head) { // 12 ms
        /*          |----|
         *          |    |   c
         * ---------|----|
         *      a      b (meet at here)
         *
         * suppose b+c = r
         * slow = a+b; fast = a+b+r; slow * 2 = fast;
         * so: a + b = r, so when meet, move fast to head, and move until meet, will get length of a
         */
        if (!head || !head->next) { return nullptr; }
        auto slow = head, fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { break; }
        }
        if (slow == nullptr || slow != fast) { return nullptr; }
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};