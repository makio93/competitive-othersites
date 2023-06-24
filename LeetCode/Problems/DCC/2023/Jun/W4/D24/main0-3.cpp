// 自力TLE3

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_set<int> vst;
    vector<TrieNode*> next;
    TrieNode(int val) {
        vst.insert(val);
        next.resize(2);
    }
};
struct Trie {
    int blen;
    TrieNode* root;
    Trie(int bl) {
        blen = bl;
        root = new TrieNode(-1);
    }
    bool search(int tar, int val, int di=0, TrieNode* tnode=nullptr) {
        if (di == blen) return true;
        if (di == 0) tnode = root;
        if (tar&(1<<di)) {
            if (tnode->next[1-((tar>>di)&1)] == nullptr || tnode->next[1-((tar>>di)&1)]->vst.find(val) == tnode->next[1-((tar>>di)&1)]->vst.end()) return false;
            else return search(tar, val, di+1, tnode->next[1-((tar>>di)&1)]);
        }
        else {
            if (tnode->next[1-((tar>>di)&1)] != nullptr && tnode->next[1-((tar>>di)&1)]->vst.find(val) != tnode->next[1-((tar>>di)&1)]->vst.end() && search(tar, val, di+1, tnode->next[1-((tar>>di)&1)])) return true;
            else return tnode->next[(tar>>di)&1] != nullptr && tnode->next[(tar>>di)&1]->vst.find(val) != tnode->next[(tar>>di)&1]->vst.end() && search(tar, val, di+1, tnode->next[(tar>>di)&1]);
        }
    }
    void add(int tar, int val, int di=0, TrieNode* tnode=nullptr) {
        if (di == blen) return;
        if (di == 0) tnode = root;
        if (tnode->next[(tar>>di)&1] == nullptr) tnode->next[(tar>>di)&1] = new TrieNode(val);
        else tnode->next[(tar>>di)&1]->vst.insert(val);
        add(tar, val, di+1, tnode->next[(tar>>di)&1]);
    }
};
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size(), rsum = accumulate(rods.begin(), rods.end(), 0);
        Trie tr(n);
        for (int i=0; i<1<<n; ++i) {
            int val = 0;
            for (int j=0; j<n; ++j) if (i&(1<<j)) val += rods[j];
            tr.add(i, val);
        }
        int res = 0;
        for (int i=0; i<1<<n; ++i) {
            int val = 0;
            for (int j=0; j<n; ++j) if (i&(1<<j)) val += rods[j];
            if (tr.search(i, val)) res = max(res, val);
        }
        return res;
    }
};
