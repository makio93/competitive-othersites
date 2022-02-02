#include <bits/stdc++.h>
using namespace std;

// 解説AC,手直し

struct TrieNode {
    bool fin;
    array<TrieNode*, 26> next;
    TrieNode() {
        fin = false;
        next.fill(nullptr);
    }
    void add(const char* sptr) {
        if (*sptr == '\0') fin = true;
        else {
            if (next[*sptr-'a'] == nullptr) next[*sptr-'a'] = new TrieNode();
            next[*sptr-'a']->add(sptr+1);
        }
    }
    bool search(const char* sptr) {
        if (*sptr == '\0') return fin;
        else if (*sptr == '.') {
            for (int i=0; i<26; ++i) if (next[i]!=nullptr && next[i]->search(sptr+1)) return true;
            return false;
        }
        else {
            if (next[*sptr-'a'] == nullptr) return false;
            else return next[*sptr-'a']->search(sptr+1);
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