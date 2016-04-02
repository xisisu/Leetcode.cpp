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

    ListNode* reverseList_3(ListNode* head) { // 8 ms
        if (!head) { return head; }
        ListNode* pre = nullptr;
        auto cur = head;
        while (cur) {
            auto nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};


int main() {
    Solution sol;
    std::vector<int> list = {0,1,2,3,4,5,6};
    auto a = constructListNode(list);
    printListNode(a);
    auto b = sol.reverseList_2(a);
    printListNode(b);
    auto c = sol.reverseList_3(b);
    printListNode(c);
    return 0;
}