//
// Created by Sisu on 4/12/2016.
//

/*
 * Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 * OJ's undirected graph serialization:
 * Nodes are labeled uniquely.
 *
 * We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 * As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 * The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 * First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 * Second node is labeled as 1. Connect node 1 to node 2.
 * Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 * Visually, the graph looks like the following:
 *
 *        1
 *       / \
 *      /   \
 *     0 --- 2
 *          / \
 *          \_/
 */

#include "Common.h"
#include <queue>
#include <unordered_map>

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> globalMap;

public:
    UndirectedGraphNode *cloneGraph2(UndirectedGraphNode *node) { // kind of cheat, since used global variable, 76 ms
        if (!node) { return nullptr; }
        if (globalMap.count(node)) { return globalMap[node]; }

        auto tmp = new UndirectedGraphNode(node->label);
        globalMap[node] = tmp;

        for (auto &val : node->neighbors) {
            tmp->neighbors.push_back(cloneGraph2(val));
        }

        return tmp;
    }

public:
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) { // 84 ms
    if (!node) { return nullptr; }

    std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
    std::queue<UndirectedGraphNode *> queue;
    queue.push(node);
    UndirectedGraphNode *res = nullptr;
    while (!queue.empty()) {
        auto cur = queue.front();
        queue.pop();

        UndirectedGraphNode* copy = nullptr;
        if (map.count(cur)) { copy = map[cur]; }
        else { copy = new UndirectedGraphNode(cur->label); map[cur] = copy; }

        for (auto &val : cur->neighbors) {
            if (map.count(val)) { copy->neighbors.push_back(map[val]); }
            else {
                auto tmp = new UndirectedGraphNode(val->label);
                copy->neighbors.push_back(tmp);
                map[val] = tmp;
                queue.push(val);
            }
        }
    }

    return map[node];
}
};