//
// Created by xisisu on 9/22/16.
//

/*
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the
 * minutes (0-59).
 *
 * Each LED represents a zero or one, with the least significant bit on the right.
 *
 * For example, the above binary watch reads "3:25".
 *
 * Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times
 * the watch could represent.
 *
 * Example:
 *
 * Input: n = 1
 * Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 * Note:
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should
 * be "10:02".
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>

class Solution {
public:
    std::vector<std::string> readBinaryWatch(int num) { // 3 ms
        std::set<std::string> result;
        for (int i = 0; i <= std::min(4, num); ++i) {
            auto hours = getNumber(11, i);
            auto minutes = getNumber(59, num-i);
            for (auto h : hours) {
                for (auto m : minutes) {
                    result.insert(construct(h, m));
                }
            }
        }

        std::vector<std::string> res;
        std::copy(result.begin(), result.end(), std::back_inserter(res));
        return res;
    }

private:
    std::string construct(int h, int m) {
        std::string res = std::to_string(h);
        res.append(":");
        if (m < 10) { res.append("0"); }
        res.append(std::to_string(m));
        return res;
    }

private:
    int countOnes(int i) {
        int res = 0;
        while (i > 0) {
            if (i & 1) { ++res; }
            i >>= 1;
        }
        return res;
    }

private:
    std::vector<int> getNumber(int limit, int numberOfOnes) {
        std::vector<int> result;
        for (int i = 0; i <= limit; ++i) {
            if (countOnes(i) == numberOfOnes) { result.push_back(i); }
        }
        return result;
    }
};

int main() {
    Solution sol;
    auto res = sol.readBinaryWatch(1);
    for (auto c : res) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return 0;
}