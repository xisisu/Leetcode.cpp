//
// Created by xisisu on 6/5/16.
//

/*
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */

#include "Common.h"
#include <string>
#include <map>

class TrieNode {
public:
    bool _isWord;
    std::map<char, TrieNode*> _children;

public:
    // Initialize your data structure here.
    TrieNode() : _isWord(false) { _children.clear(); }

public:
    void print() {
        for (auto const& v : _children) {
            std::cout << "[" << v.first << ", " << v.second->_isWord << "], ";
            v.second->print();
        }
    }
};

class Trie { // 152 ms
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(std::string word) {
        auto cur = root;
        for (auto const&w : word) {
            if (!cur->_children.count(w)) { cur->_children[w] = new TrieNode(); }
            cur = cur->_children.at(w);
        }
        cur->_isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(std::string word) {
        auto cur = root;
        for (auto const&w : word) {
            if (!cur->_children.count(w)) { return false; }
            cur = cur->_children.at(w);
        }
        return cur->_isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(std::string prefix) {
        auto cur = root;
        for (auto const&w : prefix) {
            if (!cur->_children.count(w)) { return false; }
            cur = cur->_children.at(w);
        }
        return true;
    }

public:
    void print() {
        root->print();
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
    std::vector<std::string> insert = {"app", "apple", "beer", "add", "jam", "rental"};
    std::vector<std::string> search = {"apps", "app", "ad", "applepie", "rest", "jan", "rent", "beer", "jam"};
    std::vector<std::string> prefix = {"app", "ad", "applepie", "rest", "jan", "rent", "beer", "jam"};

    Trie trie;
    std::cout << std::endl << "insert: ";
    for (auto const& word : insert) {
        std::cout << word << ", ";
        trie.insert(word);
    }

    trie.print();

    std::cout << std::endl << "search: ";
    for (auto const& word : search) {
        std::cout << "["<< word << ", " << trie.search(word) << "], ";
    }

    std::cout << std::endl << "prefix: ";
    for (auto const& word : prefix) {
        std::cout << "["<< word << ", " << trie.startsWith(word) << "], ";
    }

    std::cout << std::endl;

    return 0;
}