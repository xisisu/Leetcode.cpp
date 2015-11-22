//
// Created by Sisu on 11/22/2015.
//

/*
 * You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of
 * you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner.
 * You will take the first turn to remove the stones.
 * Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you
 * can win the game given the number of stones in the heap.
 * For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or
 * 3 stones you remove, the last stone will always be removed by your friend.
 * Hint:
 * If there are 5 stones in the heap, could you figure out a way to remove the stones such that
 * you will always be the winner?
 */

#include <iostream>
#include <vector>


class Solution {
public:
    bool canWinNim(int n) { // 0 ms
        // if left with [1-3], win for sure
        // if left with [4]  , fail for sure
        // if left with [5,6,7], can always make it 4 so the friend will fail, so win for sure
        // if left with [8], friend can always make me left with 4, so fail for sure
        // and go on
        return n%4 != 0;
    }
};

int main() {
    Solution sol;
    std::vector<int> tests;
    for (int i = 1; i < 100; ++i) { tests.push_back(i); }
    for (const auto & item : tests) {
        std::cout << item << ", " << sol.canWinNim(item) << std::endl;
    }
    return 0;
}