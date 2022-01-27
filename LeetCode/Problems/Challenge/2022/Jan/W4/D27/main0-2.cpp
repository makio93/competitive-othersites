#include <bits/stdc++.h>
using namespace std;

// 自力AC2,Timeが改善,Trie木を使用

class Trie {
    int n;
    struct TrieNode {
        vector<TrieNode*> next;
        TrieNode(TrieNode* _zero=nullptr, TrieNode* _one=nullptr) : next({ _zero, _one }) {}
    };
    TrieNode* root;
public:
    Trie(int _n=31) {
        n = _n;
        root = new TrieNode();
    }
    int search(int tar) {
        auto ptr = root;
        int res = 0;
        for (int i=n-1; i>=0; --i) {
            int bval = (tar>>i) & 1;
            if (ptr->next[bval] == nullptr) bval = 1 - bval;
            ptr = ptr->next[bval];
            res += (bval<<i);
        }
        return res;
    }
    void add(int val) {
        auto ptr = root;
        for (int i=n-1; i>=0; --i) {
            int bval = (val>>i) & 1;
            if (ptr->next[bval] != nullptr) ptr = ptr->next[bval];
            else {
                ptr->next[bval] = new TrieNode();
                ptr = ptr->next[bval];
            }
        }
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), res = 0;
        Trie tr;
        for (int i=0; i<n; ++i) {
            tr.add(nums[i]);
            res = max(res, tr.search(~nums[i])^nums[i]);
        }
        return res;
    }
};
