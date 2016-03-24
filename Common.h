//
// Created by Sisu on 11/8/2015.
//

#pragma once

#include <vector>
#include <iostream>
#include <queue>

/*
 * Common helper functions
 */

std::string to_string(int val){
    if (val == 0) { return "0"; }
    std::string res;
    bool positive = true;
    if (val < 0) {
        val = -val;
        positive = false;
    }
    while (val > 0) {
        res = std::string(1, '0'+val%10) + res;
        val /= 10;
    }
    return positive ? res : "-" + res;
}


/*
 * Linked list related code
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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

void printListNode(const ListNode* input)
{
    for (auto item = input; item != nullptr; item = item->next) {
        std::cout << item->val << " -> ";
    }
    std::cout << "nullptr" << std::endl;
}

/*
 * Tree related code
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

TreeNode* constructTreeByLevel(std::vector<int> level)
{
    if (level.empty()) { return nullptr; }

    TreeNode *res = new TreeNode(level[0]);
    std::queue<TreeNode*> queue;
    queue.push(res);

    int i = 1;
    while (i < level.size()) {
        auto cur = queue.front();
        queue.pop();
        cur->left = new TreeNode(level[i++]);
        queue.push(cur->left);

        if (i < level.size()) {
            cur->right = new TreeNode(level[i++]);
            queue.push(cur->right);
        }
    }

    return res;
}

// assumes this is a full tree!!!
void printFullTree(TreeNode* root)
{
    if (!root) { std::cout << "NULL" << std::endl; return; }
    std::queue<TreeNode*> queue;
    queue.push(root);
    queue.push(nullptr); // used to print the end of current level

    while (!queue.empty()) {
        auto cur = queue.front();
        queue.pop();
        if (cur) {
            std::cout << cur->val << ",";
            if (cur->left) queue.push(cur->left);
            if (cur->right) queue.push(cur->right);
        } else {
            std::cout << std::endl;
            if (queue.empty()) { return; }
            else { queue.push(nullptr); }
        }
    }
}