//
// Created by xisisu on 5/14/16.
//

/*
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 *
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 *
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 *
 * click to show more hints.
 *
 * Hints:
 * This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <map>
#include <queue>

class Solution {
private:
    bool findAvaliableCourses(std::set<int>& classTaken, std::map<int, std::set<int>> const& requirement) {
        bool newClass = false;
        for (auto val : requirement) {
            if (val.second.empty() && !classTaken.count(val.first)) {
                newClass = true;
                classTaken.insert(val.first);
            }
        }
        return newClass;
    }

private:
    void takeCourses(std::set<int>& classTaken, std::map<int, std::set<int>>& requirement) {
        for (auto& pre : requirement) {
            for (auto val : pre.second) {
                if (classTaken.count(val)) {
                    pre.second.erase(val);
                }
            }
        }
    }

public:
    bool canFinish(int numCourses, std::vector<std::pair<int, int>> const& prerequisites) { // overTime
        if (prerequisites.empty()) { return true; }

        std::map<int, std::set<int>> requirement;
        std::set<int> classTaken;

        for (auto const pre: prerequisites) { requirement[pre.first].insert(pre.second); }
        for (int i = 0; i < numCourses; ++i) { if (!requirement.count(i)) { classTaken.insert(i); } }

        do { takeCourses(classTaken, requirement);
        } while (findAvaliableCourses(classTaken, requirement));

        return classTaken.size() == numCourses;
    }

private:
    bool findCycle(std::map<int, std::set<int>> const& requirement, int val) {
        std::set<int> visited;
        std::queue<int> queue;
        queue.push(val);
        visited.insert(val);
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            if (!requirement.count(cur)) { continue; }
            for (auto node : requirement.at(cur)) {
                if (node == val) { return true; }
                if (!visited.count(node)) {
                    visited.insert(node);
                    queue.push(node);
                }
            }
        }
        return false;
    }

public:
    bool canFinish2(int numCourses, std::vector<std::pair<int, int>> const& prerequisites) { // overTime
        if (prerequisites.empty()) { return true; }

        std::map<int, std::set<int>> requirement;
        std::set<int> classTaken;

        for (auto const pre: prerequisites) { requirement[pre.first].insert(pre.second); }
        for (int i = 0; i < numCourses; ++i) { if (!requirement.count(i)) { classTaken.insert(i); } }

        for (auto val : requirement) {
            if (findCycle(requirement, val.first)) { return false; }
        }
        return true;
    }


public:
    bool canFinish3(int numCourses, std::vector<std::pair<int, int>> const& prerequisites) { // 44 ms
        if (prerequisites.empty()) { return true; }

        std::map<int, std::set<int>> requirement;
        std::vector<int> degree(numCourses, 0); // number of prerequire classes
        for (auto const pre: prerequisites) {
            if (!requirement[pre.second].count(pre.first)) {
                requirement[pre.second].insert(pre.first);
                ++degree[pre.first];
            }
        }

        std::queue<int> queue;
        for (int i = 0; i < numCourses; ++i) { if (0 == degree[i]) { queue.push(i); } }

        int counter = 0;
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            ++counter;
            for (auto v : requirement[cur]) {
                if (--degree[v] == 0) { queue.push(v); }
            }
        }

        return counter == numCourses;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::pair<int, int>>> tests = {
//        { }
//        , {{0, 1}}
//        , {{0, 1}, {1, 0}}
//        , {{0,1}, {0,2}, {1,2}}
         {{5,8}, {3,5}, {1,9}, {4,5}, {0,2}, {1,9}, {7,8}, {4,9}}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        for (auto const& val : test) {
            std::cout << "(" << val.first << ", " << val.second << "), ";
        }
        std::cout << std::endl;

        std::cout << "result: " << sol.canFinish(10, test) << ", " << sol.canFinish2(10, test) << ", " << sol.canFinish3(10, test) << std::endl;
    }

    return 0;
}