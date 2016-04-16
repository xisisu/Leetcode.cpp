//
// Created by Sisu on 4/15/2016.
//

/*
 * Given a linked list, determine if it has a cycle in it.
 *
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
    bool hasCycle(ListNode *head) { // 28 ms
        std::unordered_set<ListNode*> seen;
        while (head) {
            if (seen.count(head)) { return true; }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }

    bool hasCycle2(ListNode *head) { // 12 ms
        if (!head) { return false; }
        auto slow = head, fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { return true; }
        }
        return false;
    }
};