// 解説AC3

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int cnt;
    unordered_map<int, TrieNode*> next;
    TrieNode() { cnt = 0; }
};
class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode; }
    void add(vector<int>& lst) {
        TrieNode *now = root;
        for (int i=0; i<(int)(lst.size()); ++i) {
            if (now->next.find(lst[i]) == now->next.end()) now->next[lst[i]] = new TrieNode;
            now = now->next[lst[i]];
            now->cnt++;
        }
    }
    int search(vector<int>& lst) {
        TrieNode *now = root;
        for (int i=0; i<(int)(lst.size()); ++i) {
            if (now->next.find(lst[i]) == now->next.end()) return 0;
            now = now->next[lst[i]];
        }
        return now->cnt;
    }
};
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        Trie *tr = new Trie;
        for (int i=0; i<n; ++i) {
            vector<int> tlst;
            for (int j=0; j<n; ++j) tlst.push_back(grid[i][j]);
            tr->add(tlst);
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            vector<int> tlst;
            for (int j=0; j<n; ++j) tlst.push_back(grid[j][i]);
            res += tr->search(tlst);
        }
        return res;
    }
};
