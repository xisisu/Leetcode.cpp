//
// Created by Sisu on 12/3/2015.
//

/*
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 */

#include <iostream>
#include <vector>
#include <cstring>

class Solution {
public:
    int countPrimes(int n) { // 40 ms
        bool table[n];
        memset(table, true, sizeof table);
        int res = n-2;
        for (int i = 2; i <= n/2; ++i) {
            if (!table[i]) { continue; }
            int cur = i*2;
            while (cur < n) {
                if (table[cur]) {
                    table[cur] = false;
                    --res;
                }
                cur += i;
            }
        }

        return res > 0 ? res : 0;
    }
};

int main() {
    Solution sol;
   for (int i = 10; i < 100; ++i) {
        std::cout << i << ", " << sol.countPrimes(i) << std::endl;
    }
    return 0;
}