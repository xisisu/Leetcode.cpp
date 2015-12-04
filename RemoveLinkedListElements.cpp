//
// Created by Sisu on 12/3/2015.
//

/*
 * Remove all elements from a linked list of integers that have value val.
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
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

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) { // 32 ms
        while (head && head->val == val) { head = head->next; }
        if (!head) { return nullptr; }

        auto cur = head;
        while (cur) {
            if (cur->next && cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5,5,5,5,5,6};
    auto list = constructListNode(tests);
    printListNode(list);
    printListNode(sol.removeElements(list, 5));
    return 0;
}