//
// Created by Sisu on 4/9/2016.
//

/*
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

#include "Common.h" // for ListNode
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
private:
    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a) { return b; }
        if (!b) { return a; }

        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        while (a && b) {
            if (a->val < b->val) {
                if (!res) { res = a; cur = a;}
                else { cur->next = a; cur = cur->next; }
                a = a->next;
            } else {
                if (!res) { res = b; cur = b; }
                else { cur->next = b; cur = cur->next; }
                b = b->next;
            }
        }
        if (a) { cur->next = a; }
        if (b) { cur->next = b; }

        return res;
    }

public:
    ListNode* sortList(ListNode* head) { // 60 ms
        if (!head || !head->next) { return head; }

        ListNode* a;
        ListNode* b;
        a = head; b = head->next;
        while (b && b->next) {
            a = a->next;
            b = b->next->next;
        }
        b = a->next;
        a->next = nullptr;
        a = head;

        a = sortList(a);
        b = sortList(b);

        return merge(a, b);
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1,2}
            , {2,1}
            , {1,2,3,4,5,6,7,8,9}
            , {9,8,7,6,5,4,3,2,1}
            , {9,6,4,7,8,1,2,3,4,6,7,0}
    };

    for (auto const& test : tests) {
        auto head = constructListNode(test);
        printListNode(head);
        auto res = sol.sortList(head);
        printListNode(res);
        std::cout << std::endl;
    }

    return 0;
}