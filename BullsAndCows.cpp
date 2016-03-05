//
// Created by Sisu on 3/3/2016.
//

/*
 * You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to
 * guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in
 * said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match
 * the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and
 * hints to eventually derive the secret number.
 *
 * For example:
 * Secret number:  "1807"
 * Friend's guess: "7810"
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls
 * and B to indicate the cows. In the above example, your function should return "1A3B".
 *
 * Please note that both secret number and friend's guess may contain duplicate digits, for example:
 * Secret number:  "1123"
 * Friend's guess: "0111"
 * In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return
 * "1A1B". You may assume that the secret number and your friend's guess only contain digits, and their lengths are
 * always equal.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <algorithm>
#include "Common.h" // to_string

class Solution {
public:
    std::string getHint(std::string secret, std::string guess) { // 24 ms
        std::map<char, int> map;
        for (const auto& c : secret) { ++map[c]; }

        int A = 0; // first loop to count A
        for (int i = 0; i < guess.size(); ++i) {
            if (guess[i] == secret[i]) { ++A; --map[guess[i]]; }
        }

        int B = 0; // second loop to count B
        for (int i = 0; i < guess.size(); ++i) {
            if (guess[i] == secret[i]) { continue; }
            if (map[guess[i]] > 0) { ++B; --map[guess[i]]; }
        }

        return to_string(A) + "A" + to_string(B) + "B";
    }

    std::string getHint_2(std::string secret, std::string guess) { // 4 ms
        int s[10], g[10];
        for (int i = 0; i < 10; ++i) { s[i] = g[i] = 0; }

        int A = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret.at(i) == guess.at(i)) { ++A; }
            else {
                ++s[secret.at(i)-'0'];
                ++g[guess.at(i)-'0'];
            }
        }

        int B = 0;
        for (int i = 0; i < 10; ++i) {
            B += std::min(s[i], g[i]);
        }

        return to_string(A) + "A" + to_string(B) + "B";
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::string, std::string>> tests = {
            { "1111", "2222" }
            , { "1234", "4321" }
            , { "", "" }
            , { "1234", "3215" }
            , { "1234", "0111" }
    };

    for (auto const& test : tests) {
        std::cout << "input: " << test.first << ", " << test.second << std::endl;
        std::cout << "result1: " << sol.getHint(test.first, test.second) << std::endl;
        std::cout << "result2: " << sol.getHint(test.first, test.second) << std::endl;
    }

    return 0;
}