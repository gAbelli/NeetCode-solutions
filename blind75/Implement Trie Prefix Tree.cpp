#include <iostream>

class Trie {
  public:
    Trie *children[26] = {nullptr};
    bool ok = false;

    Trie() {}

    ~Trie() {
        for (int i = 0; i < 26; ++i) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }

    void insert(std::string word) {
        Trie *cur = this;
        for (char c : word) {
            std::cout << c << std::endl;
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new Trie;
            }
            cur = cur->children[c - 'a'];
        }
        cur->ok = true;
    }

    bool search(std::string word) {
        Trie *cur = this;
        for (char c : word) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->ok;
    }

    bool startsWith(std::string prefix) {
        Trie *cur = this;
        for (char c : prefix) {
            if (!cur->children[c - 'a']) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};
