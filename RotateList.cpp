//
// Created by Sisu on 3/19/2016.
//

/*
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

#include <iostream>
#include <vector>
#include "Common.h" // for list

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
    int getLen(ListNode* head) {
        int res = 0;
        while (head) {
            ++res; head = head->next;
        }
        return res;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) { // 12 ms
        if (!head || !head->next) { return head; }
        auto len = getLen(head);
        k %= len;
        if (k == 0) { return head; }

        auto fast = head, slow = head;
        auto i = 0;
        while (i++ < k && fast) { fast = fast->next; }
        while (fast->next && slow->next) {
            fast = fast->next;
            slow = slow->next;
        }
        auto res = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> test = {1,2,3,4,5};
    auto head = constructListNode(test);
    printListNode(head);
    auto res = sol.rotateRight(head, 2);
    printListNode(res);
    return 0;
}