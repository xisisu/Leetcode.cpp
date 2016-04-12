//
// Created by Sisu on 4/10/2016.
//

/*
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation
 * sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the word list
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength2(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordList) { // 300 ms
        if (beginWord.size() != endWord.size() || wordList.empty() || beginWord == endWord) { return 0; }

        std::unordered_set<std::string> b, e;
        b.insert(beginWord);
        int level = 1;

        auto dict = wordList;
        while (!b.empty()) {
            for (auto cur : b) {
                for (int i = 0; i < cur.size(); ++i) {
                    auto old = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == cur[i]) { continue; }
                        cur[i] = c;
                        if (cur == endWord) { return level+1; }
                        if (dict.count(cur)) {
                            dict.erase(cur);
                            e.insert(cur); // added to nxt explore
                        }
                        cur[i] = old;
                    }
                }
            }
            b.clear();
            b.swap(e);
            ++level;
        }

        return 0;
    }

public:
    int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordList) { // 300 ms
        if (beginWord.size() != endWord.size() || wordList.empty() || beginWord == endWord) { return 0; }

        std::queue<std::string> queue[2];
        int cur = 0;
        queue[cur].push(beginWord);
        int level = 1;
        auto dict = wordList; // since we will modify the dict

        while (!queue[cur].empty()) {
            int nxt = (cur+1)%2;
            while (!queue[cur].empty()) {
                auto start = queue[cur].front();
                queue[cur].pop();

                for (int i = 0; i < start.size(); ++i) {
                    auto old = start[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == start[i]) { continue; }
                        start[i] = c;
                        if (start == endWord) { return level+1; }
                        if (dict.count(start)) {
                            dict.erase(start);
                            queue[nxt].push(start); // added to nxt explore
                        }
                        start[i] = old;
                    }
                }
            }

            cur = nxt;
            ++level;
        }

        return 0;
    }
};

int main() {
    Solution sol;
    std::unordered_set<std::string> wordList = {
            "hot", "dot", "dog", "lot", "log"
    };

    std::vector<std::pair<std::string, std::string>> tests = {
            { "hit", "abc" }
            , { "hit", "cog" }
            , { "hot", "dog" }
            , { "a", "b" }
            , { "hit", "lol" }
            , { "hit", "hit" }
            , { "", "" }
    };

    for (auto const& test : tests) {
        std::cout << "begin: " << test.first << ", end: " << test.second << ", steps: " <<
                sol.ladderLength2(test.first, test.second, wordList) << std::endl;
    }

    return 0;
}

