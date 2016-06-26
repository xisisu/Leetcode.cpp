//
// Created by xisisu on 6/25/16.
//

/*
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i to val.
 * Example:
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * Note:
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is distributed evenly.
 */

#include <iostream>
#include <vector>


class NumArray {
private:
    std::vector<int> _sum;
    std::vector<int> _num;

public:
    NumArray(std::vector<int> &nums) { // 936 ms
        _sum.clear();
        _sum.resize(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) { _sum[i] = (0 == i) ? nums[0] : nums[i] + _sum[i-1]; }
        _num = nums;
    }

    void update(int i, int val) {
        int const delta = val - _num[i];
        for (int j = i; j < _sum.size(); ++j) {
            _sum[j] += delta;
        }
        _num[i] = val;
    }

    int sumRange(int i, int j) {
        return (0 == i) ? _sum[j] : _sum[j] - _sum[i-1];
    }
};

struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b) : start(a), end(b), sum(0), left(nullptr), right(nullptr) {}
};

class NumArray2 {
// with segment tree: http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
private:
    SegmentTreeNode* _root;

    SegmentTreeNode* buildTree(std::vector<int>const &nums, int start, int end) {
        if (start > end) { return nullptr; }
        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end-start) / 2;
        root->left  = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if (root == nullptr) { return 0; }
        int diff;
        if (root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if (i > mid) { diff = modifyTree(i, val, root->right); }
        else { diff = modifyTree(i, val, root->left); }
        root->sum += diff;
        return diff;
    }

    int queryTree(int i, int j, SegmentTreeNode* root) {
        if (root == nullptr) { return 0; }
        if (root->start == i && root->end == i) { return root->sum; }
        int mid = (root->start + root->end) / 2;
        if (i > mid)  { return queryTree(i, j, root->right); }
        if (j <= mid) { return queryTree(i, j, root->left); }

        return queryTree(i, mid, root->left) + queryTree(mid+1, j, root->right);
    }

public:
    NumArray2(std::vector<int> &nums) {
        _root = buildTree(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        modifyTree(i, val, _root);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, _root);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

int main() {
    std::vector<int> tests = {0,1,2,3,4,5,6,7,8};
    NumArray array(tests);
    std::cout << array.sumRange(0,8) << std::endl;
    array.update(0, 9);
    std::cout << array.sumRange(0,8) << std::endl;

    NumArray2 array2(tests);
    std::cout << array2.sumRange(0,8) << std::endl;
    array2.update(0, 9);
    std::cout << array2.sumRange(0,8) << std::endl;

    return 0;
}