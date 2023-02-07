#include <bits/stdc++.h>
using namespace std;

// 自力TLE

class TrieNode {
    vector<int> ids;
    vector<TrieNode*> next;
public:
    TrieNode() : ids(0), next(26*26) {}
    void add(int id, string& str, int d=0) {
        int n = str.length();
        if (d == n) ids.push_back(id);
        else {
            int ch = (str[d]-'a') * 26 + (str[n-d-1]-'a');
            if (next[ch] == nullptr) next[ch] = new TrieNode();
            next[ch]->add(id, str, d+1);
        }
    }
    int search(string& pre, string& suf, int d=0) {
        int m = pre.length(), n = suf.length(), res = -1;
        if (d>=m && d>=n && !ids.empty()) res = ids.back();
        int tch = -1, rch = -1;
        if (d < m) tch = pre[d] - 'a';
        if (d < n) rch = suf[n-d-1] - 'a';
        if (tch!=-1 && rch!=-1) {
            int ch = tch * 26 + rch;
            if (next[ch] != nullptr) res = max(res, next[ch]->search(pre, suf, d+1));
        }
        else if (tch != -1) { for (int i=0; i<26; ++i) if (next[tch*26+i] != nullptr) res = max(res, next[tch*26+i]->search(pre, suf, d+1)); }
        else if (rch != -1) { for (int i=0; i<26; ++i) if (next[i*26+rch] != nullptr) res = max(res, next[i*26+rch]->search(pre, suf, d+1)); }
        else { for (int i=0; i<26; ++i) for (int j=0; j<26; ++j) if (next[i*26+j] != nullptr) res = max(res, next[i*26+j]->search(pre, suf, d+1)); }
        return res;
    }
};

class WordFilter {
    TrieNode *root;
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        root = new TrieNode();
        for (int i=0; i<n; ++i) root->add(i, words[i]);
    }
    int f(string prefix, string suffix) {
        return root->search(prefix, suffix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
