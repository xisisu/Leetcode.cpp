//
// Created by xisisu on 7/17/16.
//

/*
 * For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a
 * rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of
 * undirected edges (each edge is a pair of labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same
 * as [1, 0] and thus will not appear together in edges.
 *
 * Example 1:
 *
 * Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 *
 *         0
 *         |
 *         1
 *        / \
 *       2   3
 * return [1]
 *
 * Example 2:
 *
 * Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 *      0  1  2
 *       \ | /
 *         3
 *         |
 *         4
 *         |
 *         5
 * return [3, 4]
 *
 * Hint:
 *
 * How many MHTs can a graph have at most?
 * Note:
 *
 * (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices
 * are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
 *
 * (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::pair<int, int>> const& edges) { // 136 ms
        if (n == 1) { return {0}; }

        std::vector<std::unordered_set<int>> adj(n, std::unordered_set<int>());
        for (auto const& edge: edges) {
            adj[edge.first].insert(edge.second);
            adj[edge.second].insert(edge.first);
        }

        /* find all leaves */
        std::unordered_set<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) { leaves.insert(i); }
        }

        /* remove leaves until we find the node, or all leaves are 1 hop away */
        while (n > 2 && leaves.size() > 0) {
            n -= leaves.size();
            std::unordered_set<int> newLeaves;
            for (auto leaf : leaves) {
                auto anotherEnd = *(adj[leaf].begin()); // leaf connects to only 1 node
                adj[anotherEnd].erase(leaf);
                if (adj[anotherEnd].size() == 1) { newLeaves.insert(anotherEnd); }
                adj[leaf].clear();
            }
            leaves = newLeaves;
        }

        /* the end result has a size of either 1 (1 node) or 2 (adjecent nodes) */
        return std::vector<int>(leaves.begin(), leaves.end());
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<int, int>> edges = {
            {0, 3}
            , {1, 3}
            , {2, 3}
            , {4, 3}
            , {5, 4}
    };
    auto result = sol.findMinHeightTrees(6, edges);
    for (auto const& val : result) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    return 0;
}