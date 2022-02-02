#include <bits/stdc++.h>
using namespace std;

// 解説AC

struct TrieNode {
    bool fin;
    array<TrieNode*, 26> next;
    TrieNode() {
        fin = false;
        next.fill(nullptr);
    }
    void add(const char* sptr) {
        if (sptr[0] == '\0') fin = true;
        else {
            if (next[sptr[0]-'a'] == nullptr) next[sptr[0]-'a'] = new TrieNode();
            next[sptr[0]-'a']->add(sptr+1);
        }
    }
    bool search(const char* sptr) {
        if (sptr[0] == '\0') return fin;
        else if (sptr[0] == '.') {
            for (int i=0; i<26; ++i) if (next[i]!=nullptr && next[i]->search(sptr+1)) return true;
            return false;
        }
        else {
            if (next[sptr[0]-'a'] == nullptr) return false;
            else return next[sptr[0]-'a']->search(sptr+1);
        }
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) { root->add(word.c_str()); }
    bool search(string word) { return root->search(word.c_str()); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */