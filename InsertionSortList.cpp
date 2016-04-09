//
// Created by Sisu on 4/9/2016.
//

/*
 * Sort a linked list using insertion sort.
 */

#include <iostream>
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
public:
    ListNode* insertionSortList(ListNode* head) { // 88 ms
        ListNode* res = nullptr;

        while (head) {
            auto cur = head;
            head = head->next;
            cur->next = nullptr;

            if (!res) { res = cur; }
            else if (cur->val < res->val) { cur->next = res; res = cur; }
            else {
                auto tmp = res;
                while (tmp->next && tmp->next->val < cur->val) {
                    tmp = tmp->next;
                }
                auto nxt = tmp->next;
                tmp->next = cur;
                cur->next = nxt;
            }
        }

        return res;
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
        auto res = sol.insertionSortList(head);
        printListNode(res);
        std::cout << std::endl;
    }

    return 0;
}