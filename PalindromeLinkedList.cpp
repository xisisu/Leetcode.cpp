//
// Created by Sisu on 3/3/2016.
//

/*
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
#include "Common.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) { // 24 ms
        if (!head || !head->next) { return true; }

        // use two pointers, slow to reverse the list, while fast to advance 2 step at a time
        // when fast reaches the end, slow is at half, and already reverted
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* nxt = slow->next;
            slow->next = pre;
            pre = slow;
            slow = nxt;
        }
        if (fast) { slow = slow->next; }

        while (pre && slow) {
            if (pre->val != slow->val) { return false; }
            pre = pre->next;
            slow = slow->next;
        }

        return true;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> tests = {
            { 0,1,2,3,4}
            , {0,1,2,3,3,2,1,0}
            , {0,1,2,3,4,3,2,1,0}
    };

    for (auto const& test : tests) {
        ListNode* cur = constructListNode(test);

        std::cout << "input: ";
        printListNode(cur);
        std::cout << "result: " << sol.isPalindrome(cur) << std::endl << std::endl;
    }

    return 0;
}

