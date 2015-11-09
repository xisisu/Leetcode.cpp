//
// Created by Sisu on 11/1/2015.
//

/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and
 * each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
#include <set>
#include <map>
#include <algorithm>
#include "Common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { // 36 ms
        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        int advance = 0;
        while (l1 && l2) {
            auto val = l1->val + l2->val + advance;
            ListNode* tmp = new ListNode(val % 10);
            advance = val / 10;
            if (!res) {
                res = tmp;
            } else {
                cur->next = tmp;
            }
            cur = tmp;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (!l1) { l1 = l2; }
        while (l1) {
            if (advance == 0) {
                cur->next = l1;
                return res;
            } else {
                auto val = advance + l1->val;
                advance = val / 10;
                ListNode* tmp = new ListNode(val % 10);
                cur->next = tmp;
                cur = tmp;
            }
            l1 = l1->next;
        }
        if (advance != 0) {
            ListNode* tmp = new ListNode(advance);
            cur->next = tmp;
        }
        return res;
    }
};

int main() {
    Solution sol;
    auto a = constructListNode(std::vector<int> {1});
    auto b = constructListNode(std::vector<int> {9, 9});
    printListNode(a);
    printListNode(b);
    auto c = sol.addTwoNumbers(a, b);
    printListNode(c);

    return 0;
}