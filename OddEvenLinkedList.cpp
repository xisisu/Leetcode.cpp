//
// Created by Sisu on 3/5/2016.
//

/*
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking
 * about the node number and not the value in the nodes.
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 * Example:
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
 * Note:
 * The relative order inside both the even and odd groups should remain as it was in the input.
 * The first node is considered odd, the second node even and so on ...
 */

#include "Common.h"
#include <vector>
#include <iostream>

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
    ListNode* oddEvenList(ListNode* head) { // 20 ms
        if (!head || !head->next) { return head; }
        ListNode* even_start = head->next;

        ListNode* pre_odd    = head;
        ListNode* cur        = head->next->next;
        while (cur) {
            ListNode* pre_even = pre_odd->next;
            pre_odd->next  = cur;
            pre_even->next = cur->next;
            pre_odd        = cur;

            if (!cur->next) { break; }
            cur            = cur->next->next;
        }

        pre_odd->next = even_start;

        return head;
    }
};

int main() {
    Solution sol;
    ListNode* input = constructListNode({1,2,3,4,5});
    printListNode(input);
    auto res = sol.oddEvenList(input);
    printListNode(res);
    return 0;
}