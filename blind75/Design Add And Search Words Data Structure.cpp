#include <iostream>

class WordDictionary {
  public:
    WordDictionary *children[26] = {nullptr};
    bool ok = false;

    WordDictionary() {}
    ~WordDictionary() {
        for (int i = 0; i < 26; ++i) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }

    void addWord(std::string word) {
        WordDictionary *cur = this;
        std::cout << std::endl;
        for (char c : word) {
            std::cout << c << std::endl;
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new WordDictionary;
            }
            cur = cur->children[c - 'a'];
        }
        std::cout << "set ok" << std::endl;
        cur->ok = true;
    }

    bool search(std::string word) { return searchHelper(word, 0); }

    bool searchHelper(const std::string &word, int start) {
        if (start == word.size() - 1) {
            return ok;
        }
        if (word[start] == '.') {
            bool found = false;
            for (int i = 0; i < 26; ++i) {
                if (children[i] && children[i]->searchHelper(word, start + 1)) {
                    found = true;
                    break;
                }
            }
            return found;
        } else {
            if (!children[word[start] - 'a']) {
                return false;
            }
            return children[word[start] - 'a']->searchHelper(word, start + 1);
        }
    }
};
