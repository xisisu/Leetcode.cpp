//
// Created by Sisu on 3/20/2016.
//

/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the
 * original list.
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

#include <iostream>
#include <vector>
#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) { // 8 ms
        if (!head || !head->next) { return head; }

        // find first non-duplicate elements
        ListNode* res = nullptr;
        ListNode* resCur = nullptr;
        auto pre = head, cur = head->next;
        do {
            if (!cur || pre->val != cur->val) {
                if (!res) { res = pre; resCur = pre; }
                else { resCur->next = pre; resCur = pre; }
                pre = cur;
                cur = pre ? pre->next : nullptr;
            } else { // cur must be present, and pre->val == cur->val, repeat elements
                while (cur->next && cur->val == cur->next->val) { cur = cur->next; }
                if (!cur->next) { break; }
                else { pre = cur->next; cur = pre->next; }
            }
        } while (pre);

        if (resCur) { resCur->next = nullptr; }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            {}
            , {1,2,3,3}
            , {1,2,3}
            , {1,1,1,1,1}
            , {1,1,2,2}
            , {1,2,2,3}
            , {1,1,2,3}
    };

    for (auto const& test : tests) {
        auto input = constructListNode(test);
        std::cout << "before: ";
        printListNode(input);
        auto res = sol.deleteDuplicates(input);
        std::cout << "after: ";
        printListNode(res);
        std::cout << std::endl;
    }

    return 0;
}