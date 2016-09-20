//
// Created by xisisu on 9/19/16.
//

/*
 *  Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function
 *  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   
 *
 * Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) { // 59 ms
        if (ransomNote.empty()) { return true; }
        if (magazine.empty() || magazine.size() < ransomNote.size()) { return false; }

        std::map<char, int> map;
        for (auto const c : ransomNote) { ++map[c]; }
        for (auto c : magazine) {
            if (map.find(c) == map.end()) { continue; }
            --map[c];
            if (map[c] == 0) { map.erase(c); }
            if (map.empty()) { return true; }
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::pair<std::string, std::string>> tests = {
            {"", "asdf"}
            , {"asdf", ""}
            , {"asdf", "asdf"}
            , {"a", "b"}
            , {"aa", "ab"}
            , {"aa", "aab"}
            , {"bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"}
    };

    for (auto const test: tests) {
        std::cout << test.first << ", " << test.second << ": " << sol.canConstruct(test.first, test.second) << std::endl;
    }

    return 0;
}