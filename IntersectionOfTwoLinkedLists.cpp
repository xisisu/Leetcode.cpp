//
// Created by Sisu on 11/29/2015.
//

/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists:
 *
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
#include <unordered_set>
#include <cstdlib>

class Solution {
public:
    int length(ListNode* node) {
        int res = 0;
        while (node) {
            ++res; node = node->next;
        }
        return res;
    }

    ListNode *getIntersectionNode_2(ListNode *headA, ListNode *headB) { //
        auto l1 = length(headA), l2 = length(headB);
        int diff = std::abs(l1 - l2);
        if (l1 > l2) {
            while (diff-- > 0 && headA) { headA = headA->next; }
        } else {
            while (diff-- > 0 && headB) { headB = headB->next; }
        }

        while (headA && headB) {
            if (headA == headB) { return headA; }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { // 76 ms
        std::unordered_set<ListNode*> set;
        while (headA) {
            set.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (set.count(headB)) { return headB; }
            headB = headB->next;
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests = {1,2,3,4,5};
    auto headA = constructListNode(tests);
    auto headB = constructListNode(std::vector<int>{7,8});
    headB->next->next = headA->next;

    auto res = sol.getIntersectionNode_2(headA, headB);
    printListNode(res);
    return 0;
}