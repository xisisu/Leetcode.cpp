//
// Created by Sisu on 11/8/2015.
//

#ifndef LEETCODE_CPP_COMMON_H
#define LEETCODE_CPP_COMMON_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* constructListNode(const std::vector<int>& list)
{
    ListNode *res = nullptr;
    ListNode *cur = nullptr;
    for (const auto& item: list) {
        ListNode *tmp = new ListNode(item);
        if (!res) { // first node
            res = tmp;
        } else {
            cur->next = tmp;
        }
        cur = tmp;
    }
    return res;
}

void printListNode(const ListNode* input) {
    for (auto item = input; item != nullptr; item = item->next) {
        std::cout << item->val << " -> ";
    }
    std::cout << "nullptr" << std::endl;
}

#endif //LEETCODE_CPP_COMMON_H
