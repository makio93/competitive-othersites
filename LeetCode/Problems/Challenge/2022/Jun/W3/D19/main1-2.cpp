// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        bool isword;
        vector<Node*> next;
        Node() : isword(false), next(26, NULL) {}
    } *root;
    void dfs(vector<string>& rlst, string& word, Node* cur, int di) {
        if ((int)(rlst.size()) >= di) return;
        if (cur->isword) rlst.push_back(word);
        for (int i=0; i<26; ++i) if (cur->next[i] != NULL) {
            word.push_back((char)('a'+i));
            dfs(rlst, word, cur->next[i], di);
            word.pop_back();
        }
    }
public:
    Trie() { root = new Node(); }
    void insert(string& word) {
        Node *cur = root;
        for (char& ci : word) {
            if (cur->next[ci-'a'] == NULL) cur->next[ci-'a'] = new Node();
            cur = cur->next[ci-'a'];
        }
        cur->isword = true;
    }
    vector<string> suggest(string prefix, int di=3) {
        vector<string> rlst;
        Node *cur = root;
        for (char& ci : prefix) {
            if (cur == NULL) break; 
            cur = cur->next[ci-'a'];
        }
        if (cur == NULL) return rlst;
        dfs(rlst, prefix, cur, di);
        return rlst;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        Trie *dict = new Trie();
        for (int i=0; i<n; ++i) dict->insert(products[i]);
        vector<vector<string>> res;
        string tar = "";
        for (char& ci : searchWord) {
            tar.push_back(ci);
            res.push_back(dict->suggest(tar));
        }
        return res;
    }
};
