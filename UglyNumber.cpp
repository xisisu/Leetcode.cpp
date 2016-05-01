//
// Created by Sisu on 5/1/2016.
//

/*
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is
 * not ugly since it includes another prime factor 7.
 * Note that 1 is typically treated as an ugly number.
 */

#include <iostream>
#include <vector>

class Solution {
 public:
  bool isUgly(int num) {
      if (num == 0) { return false; }
      while (num != 1) {
          if (num % 2 == 0) { num /= 2; }
          else if (num % 3 == 0) { num /= 3; }
          else if (num % 5 == 0) { num /= 5; }
          else { return false; }
      }
      return true;
  }
};

int main() {
    Solution sol;
    std::vector<int> tests = {0,1,2,3,4,5,6,7,8,9,10};
    for (auto const& test : tests) {
        std::cout << test << ", " << sol.isUgly(test) << std::endl;
    }
    return 0;
}
