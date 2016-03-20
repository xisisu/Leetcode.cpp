//
// Created by Sisu on 3/20/2016.
//

/*
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or
 * equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */

#include <iostream>
#include <vector>
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
    ListNode* partition(ListNode* head, int x) { // 8 ms
        if (!head || !head->next) { return head; }

        ListNode* small = nullptr;
        ListNode* smallTail = nullptr;
        ListNode* large = nullptr;
        ListNode* largeTail = nullptr;

        auto cur = head;
        while (cur) {
            if (cur->val < x) {
                if (!small) { small = cur; smallTail = cur; }
                else { smallTail->next = cur; smallTail = cur; }
            } else {
                if (!large) { large = cur; largeTail = cur; }
                else { largeTail->next = cur; largeTail = cur; }
            }
            cur = cur->next;
        }

        if (!small) { return large; } // all large
        smallTail->next = large;
        if (largeTail) { largeTail->next = nullptr; } // all small

        return small;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::vector<int>, int>> tests = {
            { {}, 0 }
            , { {1,1,1,1,1,1,1}, 0 }
            , { {1,1,1,1,1,1,1}, 1 }
            , { {1,1,1,1,1,1,1}, 2 }
            , { {1,4,3,2,5,2}, 3 }
    };

    for (auto& test : tests) {
        auto input = constructListNode(test.first);
        std::cout << "data: ";
        printListNode(input);
        std::cout << "partition by: " << test.second << std::endl;

        auto res = sol.partition(input, test.second);
        std::cout << "result: ";
        printListNode(res);
        std::cout << std::endl;
    }

    return 0;
}