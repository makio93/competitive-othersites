// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        int d;
        bool leaf;
        vector<TrieNode*> next;
        TrieNode(int d=0, bool leaf=true) : d(d), leaf(leaf), next(vector<TrieNode*>(26, nullptr)) {}
        void add(string& word, int id=-1) {
            if (id == -1) id = word.length() - 1;
            if (next[word[id]-'a'] == nullptr) {
                next[word[id]-'a'] = new TrieNode(d+1);
                if (leaf) leaf = false;
            }
            if (id > 0) next[word[id]-'a']->add(word, id-1);
        }
        int score() {
            if (leaf) return d + 1;
            int rval = 0;
            for (int i=0; i<26; ++i) if (next[i] != nullptr) rval += next[i]->score();
            return rval;
        }
    };
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode(0);
        for (int i=0; i<n; ++i) root->add(words[i]);
        return root->score();
    }
};
