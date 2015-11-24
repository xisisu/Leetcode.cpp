//
// Created by Sisu on 11/23/2015.
//

/*
 * Reverse a singly linked list.
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "common.h"
#include <iostream>
#include <vector>

class Solution {
public:
    ListNode* reverseList(ListNode* head) { // 8 ms
        if (!head || !head->next) { return head; }
        auto pre = head, cur = head->next;
        head->next = nullptr; // head is tail, clear its next
        while (cur) {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* reverseList_2(ListNode* head) { // 8 ms
        if (!head || !head->next) { return head; }
        auto res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};


int main() {
    Solution sol;
    std::vector<int> list = {0,1,2,3,4,5,6};
    auto a = constructListNode(list);
    printListNode(a);
    auto b = sol.reverseList_2(a);
    printListNode(b);
    return 0;
}