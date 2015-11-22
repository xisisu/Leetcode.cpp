//
// Created by Sisu on 11/22/2015.
//

/*
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
 * the linked list should become 1 -> 2 -> 4 after calling your function.
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
    void deleteNode(ListNode* node) { // 16 ms
        if (!node) { return; }
        else if (!node->next) { node = nullptr; }
        else { node->val = node->next->val; node->next = node->next->next; }
    }
};

int main() {
    Solution sol;

    std::vector<int> tests = {1, 2, 3, 4, 5};
    auto res = constructListNode(tests);
    printListNode(res);

    sol.deleteNode(res);
    printListNode(res);

    return 0;
}