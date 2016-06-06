//
// Created by xisisu on 6/5/16.
//

/*
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means
 * it can represent any one letter.
 *
 * For example:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

class TrieNode {
public:
    bool _isWord;
    std::map<char, TrieNode*> _children;

public:
    // Initialize your data structure here.
    TrieNode() : _isWord(false) { _children.clear(); }

    void addWord(std::string word) {
        auto cur = this;
        for (auto const&w : word) {
            if (!cur->_children.count(w)) { cur->_children[w] = new TrieNode(); }
            cur = cur->_children.at(w);
        }
        cur->_isWord = true;
    }

    bool search(std::string word) {
        if (word.empty()) { return this->_isWord; }

        auto cur = this;
        for (int i = 0; i < word.size(); ++i) {
            auto w = word.at(i);
            if ('.' == w) {
                auto subString = word.substr(i+1);
                for (auto child : cur->_children) {
                    if (child.second->search(subString)) { return true; }
                }
                return false;
            } else {
                if (!cur->_children.count(w)) { return false; }
                cur = cur->_children.at(w);
            }
        }
        return cur->_isWord;
    }

public:
    void print() {
        for (auto const& v : _children) {
            std::cout << "[" << v.first << ", " << v.second->_isWord << "], ";
            v.second->print();
        }
    }
};

class WordDictionary { // 212 ms
public:
    WordDictionary() { root = new TrieNode(); }

    // Adds a word into the data structure.
    void addWord(std::string word) { root->addWord(word); }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(std::string word) { return root->search(word); }

private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
    std::vector<std::string> insert = {"at", "and", "an", "add", "bat"};
    std::vector<std::string> search = {"a", ".at", ".at", "am.", "a.d.", "b.", "a.d", "."};

    WordDictionary wordDictionary;
    std::cout << std::endl << "insert: ";
    for (auto const& word : insert) {
        std::cout << word << ", ";
        wordDictionary.addWord(word);
    }

    std::cout << std::endl << "search: ";
    for (auto const& word : search) {
        std::cout << "[" << word << ", " << wordDictionary.search(word) << "], ";
    }
    std::cout << std::endl;
    return 0;
}