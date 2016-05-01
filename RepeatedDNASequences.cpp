//
// Created by Sisu on 4/30/2016.
//

/*
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When
 * studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 * For example,
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>

class Solution {
private:
    static constexpr int _strLen = 10;

public:
    std::vector<std::string> findRepeatedDnaSequences(std::string const& s) { // 132 ms
        if (s.size() < _strLen + 1) { return {}; }

        std::unordered_map<std::string, int> map;
        std::vector<std::string>             res;
        for (int i = 0; i <= s.size() - _strLen; ++i) {
            auto cur = s.substr(i, _strLen);
            if (2 == ++map[cur]) { res.push_back(cur); }
        }

        return res;
    }

private:
    static constexpr int32_t      _mask = 0x00FFFFF; // lower 20 bits are 1, used to mask out all higher bits
    std::unordered_map<char, int> _dict;

public:
    Solution() {
        _dict = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    }

public:
    std::vector<std::string> findRepeatedDnaSequences2(std::string const& s) { // 108 ms
        /*
         * there are only four chars, ACTG. Can map to number 0-3. As a result, can be represented by 2 bits.
         * a 10 characters string can be represented by 20 bits, or a 32-bit integer.
         */
        if (s.size() < _strLen + 1) { return {}; }
        std::unordered_map<int, int> map;
        std::vector<std::string>     res;

        int32_t cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            cur <<= 2; cur &= _mask; // get rid of the higher 2 bits
            auto val = _dict[s[i]]; cur |= val; // add lower 2 bits to the cur
            if (i < _strLen - 1) { continue; } // if length is not enough, skip it
            if (2 == ++map[cur]) { res.push_back(s.substr(i - _strLen + 1, _strLen)); }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> tests = {
            ""
            , "AAAAAAAAAAA"
            , "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTTAAAA"
            , "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTTAAAAACCCCCAAAAACCCCCC"
    };

    for (auto const& test : tests) {
        std::cout << "input: " << test << std::endl;
        auto res1 = sol.findRepeatedDnaSequences(test);
        std::cout << "res 1: ";
        std::copy(res1.begin(), res1.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << std::endl;
        auto res2 = sol.findRepeatedDnaSequences2(test);
        std::cout << "res 2: ";
        std::copy(res2.begin(), res2.end(), std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << std::endl << std::endl;
    }

    return 0;
}