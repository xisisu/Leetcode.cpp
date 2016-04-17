//
// Created by Sisu on 4/16/2016.
//

/*
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station
 * (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */

#include <iostream>
#include <vector>
#include <iterator>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) { // 12 ms
        if (gas.size() != cost.size()) { return -1; } // invalid input
        if (gas.empty()) { return 0; }
        int n = gas.size();

        for (int start = 0; start < n; ++start) {
            int cur_sum = gas[start] - cost[start], nxt = (start + 1) % n;
            while (cur_sum >= 0) {
                cur_sum += gas[nxt] - cost[nxt];
                nxt = (nxt + 1) % n;
                if (cur_sum >= 0 && nxt == start) { return start; }
            }
            start = std::max(start, nxt - 1);
        }

        return -1;
    }

    int canCompleteCircuit2(std::vector<int>& gas, std::vector<int>& cost) { // 9 ms
        if (gas.size() != cost.size()) { return -1; } // invalid input

        for (int i = 0; i < gas.size(); ++i) {
            // start with i
            int sum = 0, start = i, cur = start;
            do {
                sum += (gas[cur] - cost[cur]);
                if (++cur == gas.size()) { cur = 0; } // reset to 0;
                if (sum >= 0 && cur == start) { return start; }
            } while (sum >= 0);
            i = std::max(i, cur-1); // start with cur to speed up, since we already know cannot start before cur
        }

        return -1; // no route
    }
};

int main() {
    Solution sol;
    std::vector<int> gas = {31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    std::vector<int> cost = {36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

    std::cout << sol.canCompleteCircuit2(gas, cost) << std::endl;
    return 0;
}