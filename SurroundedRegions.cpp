//
// Created by Sisu on 4/11/2016.
//

/*
 * Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>

class Solution {
private:
    void mark(std::vector<std::vector<char>>& board, int i, int j, std::vector<std::vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) { return; }
        if (visited[i][j]) { return; }
        visited[i][j] = true;
        if (board[i][j] == 'O') {
            board[i][j] = '@';
            mark(board, i+1, j, visited);
            mark(board, i-1, j, visited);
            mark(board, i, j+1, visited);
            mark(board, i, j-1, visited);
        }
    }

public:
    void solve(std::vector<std::vector<char>>& board) { // timeout because too deep in stack
        /*
         * all non-surrounded regions starts with edge, replace them with @, then flip all surrended regions
         * note the visited here, otherwise the recursion is too deep and it will overflow
         */
        if (board.empty() || board[0].empty()) { return; }

        auto M = board.size(), N = board[0].size();
        std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));

        // 1. turn non surrended regions to '@'
        for (int i = 0; i < M; ++i) {
            mark(board, i, 0, visited);
            mark(board, i, N-1, visited);
        }
        for (int j = 0; j < N; ++j) {
            mark(board, 0, j, visited);
            mark(board, M-1, j, visited);
        }

        // 2. flip all surrended regions to 'X', at the same time, restore non_surrended regions
        for (auto& row : board) {
            for (auto& val : row) {
                if (val == '@') { val = 'O'; }
                else if (val == 'O') { val = 'X'; }
            }
        }
    }

private:
    struct Node {
        int x, y;
        Node(int x_, int y_) : x(x_), y(y_) {}
    };

public:
    void solve2(std::vector<std::vector<char>>& board) { // 16 ms
        if (board.empty() || board[0].empty()) { return; }
        auto M = board.size(), N = board[0].size();

        std::queue<Node> queue;
        for (int i = 0; i < M; ++i) {
            if (board[i][0] == 'O') { queue.push(Node(i, 0)); }
            if (board[i][N-1] == 'O') { queue.push(Node(i, N-1)); }
        }
        for (int i = 0; i < N; ++i) {
            if (board[0][i] == 'O') { queue.push(Node(0, i)); }
            if (board[M-1][i] == 'O') { queue.push(Node(M-1, i)); }
        }

        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            auto x = cur.x, y = cur.y;
            if (board[x][y] != 'O') { continue; }
            board[x][y] = 'A';
            if (x > 0 && board[x-1][y] == 'O') { queue.push(Node(x-1, y)); }
            if (y > 0 && board[x][y-1] == 'O') { queue.push(Node(x, y-1)); }
            if (x < M-1 && board[x+1][y] == 'O') { queue.push(Node(x+1, y)); }
            if (y < N-1 && board[x][y+1] == 'O') { queue.push(Node(x, y+1)); }
        }

        // 2. flip all surrended regions to 'X', at the same time, restore non_surrended regions
        for (auto& row : board) {
            for (auto& val : row) {
                if (val == 'A') { val = 'O'; }
                else if (val == 'O') { val = 'X'; }
            }
        }
    }
};

inline void printMatrix(std::vector<std::vector<char>>const& board) {
    for (auto const& row : board) {
        std::copy(row.begin(), row.end(), std::ostream_iterator<char>(std::cout, ""));
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;
    std::vector<std::vector<char>> board = {
              { 'X', 'X', 'X', 'X' }
            , { 'X', 'O', 'O', 'X' }
            , { 'X', 'X', 'O', 'X' }
            , { 'X', 'O', 'X', 'X' }
    };

    printMatrix(board);
    sol.solve2(board);
    printMatrix(board);

    return 0;
}