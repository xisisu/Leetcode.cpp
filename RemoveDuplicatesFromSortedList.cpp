//
// Created by Sisu on 11/28/2015.
//

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
#include "common.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) { // 16 ms
        auto cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
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
    std::vector<int> tests = {1,1,2,2};
    auto input = constructListNode(tests);
    printListNode(input);
    auto output = sol.deleteDuplicates(input);
    printListNode(output);
    return 0;
}