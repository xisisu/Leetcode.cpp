//
// Created by xisisu on 5/14/16.
//

/*
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 *
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 *
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 *
 * click to show more hints.
 *
 * Hints:
 * This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
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
    bool takeClass(std::vector<int>& result, std::set<int>& visited, std::map<int, std::set<int>>& requirement) {
        bool newClass = false;
        for (auto& pre : requirement) {
            for (auto val : pre.second) {
                if (visited.count(val)) { pre.second.erase(val); }
            }
            if (!visited.count(pre.first) && pre.second.empty()) {
                visited.insert(pre.first);
                result.push_back(pre.first);
                newClass = true;
            }
        }
        return newClass;
    }

public:
    std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>> const& prerequisites) { // 1548 ms
        std::vector<int> result;
        std::set<int> visited;
        std::map<int, std::set<int>> requirement;

        for (auto const pre : prerequisites) { requirement[pre.first].insert(pre.second); }
        for (int i = 0; i < numCourses; ++i) { if(!requirement.count(i)) { result.push_back(i); visited.insert(i); } }

        while (takeClass(result, visited, requirement)) { ; }

        return result.size() == numCourses ? result : std::vector<int>();
    }


public:
    std::vector<int> findOrder2(int numCourses, std::vector<std::pair<int, int>> const& prerequisites) { // 60 ms
        std::map<int, std::set<int>> requirement;
        std::vector<int> degree(numCourses, 0);
        for (auto const& pre: prerequisites) {
            if (!requirement[pre.second].count(pre.first)) {
                requirement[pre.second].insert(pre.first);
                ++degree[pre.first];
            }
        }

        std::queue<int> queue;
        for (int i = 0; i < numCourses; ++i) {
            if (0 == degree[i]) { queue.push(i); }
        }

        std::vector<int> result;
        while (!queue.empty()) {
            auto cur = queue.front();
            queue.pop();
            result.push_back(cur);
            for (auto v : requirement[cur]) {
                if (--degree[v] == 0) { queue.push(v); }
            }
        }

        return result.size() == numCourses ? result : std::vector<int>();
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<std::pair<int, int>>> tests = {
            { }
            , {{0, 1}}
            , {{0, 1}, {1, 0}}
            , {{0,1}, {0,2}, {1,2}}
            , {{5,8}, {3,5}, {1,9}, {4,5}, {0,2}, {1,9}, {7,8}, {4,9}}
    };

    for (auto const& test : tests) {
        std::cout << "input: ";
        for (auto const& val : test) {
            std::cout << "(" << val.first << ", " << val.second << "), ";
        }
        std::cout << std::endl;

        auto res1 = sol.findOrder(10, test);
        std::cout << "result: ";
        std::copy(res1.begin(), res1.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;

        auto res2 = sol.findOrder2(10, test);
        std::cout << "result: ";
        std::copy(res2.begin(), res2.end(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    }

    return 0;
}