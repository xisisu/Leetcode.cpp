//
// Created by Sisu on 3/20/2016.
//

/*
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those
 * horizontally or vertically neighboring. The same letter cell may not be used more than once.
 * For example,
 * Given board =
 *
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string.h>
#include <map>

class Solution {
private:
    bool helper(std::vector<std::vector<char>> const& board
                , std::string const& word
                , std::vector<std::vector<bool>>& used
                , int i
                , int j
                , int cur)
    {
        /* always check found or not first, then check other cases */
        if (cur == word.size()) { return true; } // searched to the end, must match

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) { return false; } // invalid index
        if (used[i][j]) { return false; } // this char is already used
        if (word.at(cur) != board[i][j]) { return false; } // does not match

        used[i][j] = true;
        bool res = helper(board, word, used, i+1, j, cur+1) ||
                    helper(board, word, used, i-1, j, cur+1) ||
                    helper(board, word, used, i, j+1, cur+1) ||
                    helper(board, word, used, i, j-1, cur+1);
        used[i][j] = false;
        return res;
    }

public:
    bool exist(std::vector<std::vector<char>> const& board, std::string const& word) { // 87 ms
        if (board.empty() || board[0].empty()) { return false; }
        auto M = board.size(), N = board[0].size();

        /* some sanity check */
        if (word.size() > M*N) { return false; }
        std::map<char, int> validChars;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                validChars[board[i][j]]++;
            }
        }
        for (auto const& c : word) {
            if (--validChars[c] < 0) { return false; }
        }

        std::vector<std::vector<bool>> used(M, std::vector<bool>(N, false));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (helper(board, word, used, i, j, 0)) { return true; }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<char>> data = {
              { 'A', 'B', 'C', 'E' }
            , { 'S', 'F', 'C', 'S' }
            , { 'A', 'D', 'E', 'F' }
    };
    std::vector<std::string> tests = {
            "ABCCED"
            , "SEE"
            , "ABCB"
    };

    for (auto const& test : tests) {
        std::cout << "input: " << test << ", " << sol.exist(data, test) << std::endl;
    }
    return 0;
}
