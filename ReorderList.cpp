//
// Created by Sisu on 4/16/2016.
//

/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

#include "Common.h"

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
    ListNode* reverseList(ListNode* head) {
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

public:
    void reorderList(ListNode* head) { // 68 ms
        if (!head || !head->next) { return; } // nullptr or single node list requires no op

        // 1. find the middle of the list
        auto slow = head, fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. now slow points to middle, break it to two lists
        auto second = reverseList(slow->next);
        slow->next = nullptr;

        // 3. now merge
        auto first = head;
        auto curFirst = first, curSecond = second;
        while (curFirst && curSecond) {
            auto tempFirst = curFirst->next, tempSecond = curSecond->next;
            curFirst->next = curSecond;
            curSecond->next = tempFirst;
            curFirst = tempFirst;
            curSecond = tempSecond;
        }
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1}
            , {1,2}
            , {1,2,3}
            , {1,2,3,4}
            , {1,2,3,4,5}
    };

    for (auto const& test : tests) {
        std::cout << "before: ";
        auto head = constructListNode(test);
        printListNode(head);

        sol.reorderList(head);
        std::cout << "after:  ";
        printListNode(head);
        std::cout << std::endl;
    }

    return 0;
}