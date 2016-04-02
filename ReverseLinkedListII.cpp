//
// Created by Sisu on 4/2/2016.
//

/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

#include "Common.h" // for ListNode

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
    ListNode* reverseBetween(ListNode* head, int m, int n) { // 4 ms
        /*
         * assuming we have 1 <= m <= n
         */
        if (!head || n <= m) { return head; }

        ListNode* preTail = nullptr;
        ListNode* curTail = nullptr;
        ListNode* pre     = nullptr;
        ListNode* cur     = head;

        // special case handling when m == 1
        for (int i = 1; i <= n; ++i) {
            if (i == m-1) { preTail = cur; }
            else if (i == m) { curTail = cur; }

            if (i < m) {
                cur = cur->next;
            } else { // i >= m
                auto nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
        }

        if (!preTail) { head = pre; }
        else { preTail->next = pre; }
        curTail->next = cur;

        return head;
    }
};

int main() {
    Solution sol;
    std::vector<int> data = {1,2,3,4,5};
    std::vector<std::pair<int, int>> tests = {
            {2,4}
            , {1,5}
            , {1,2}
            , {4,5}
            , {1,1}
    };

    for (auto const& test : tests) {
        std::cout << std::endl << test.first << ", " << test.second << ": ";
        auto head = constructListNode(data);
        auto res = sol.reverseBetween(head, test.first, test.second);
        printListNode(res);
    }

    return 0;
}