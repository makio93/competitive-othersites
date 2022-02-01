#include <bits/stdc++.h>
using namespace std;

// 自力WA

class WordFilter {
    class TrieNode {
        int rchs;
        vector<int> ids;
        vector<TrieNode*> next;
    public:
        TrieNode() : rchs(0), next(26, nullptr), ids(0) {}
        void add(int id, string& str, int d=0) {
            int n = str.length();
            if (d == n) ids.push_back(id);
            else {
                int ch = str[d] - 'a', rch = str[n-d-1] - 'a';
                if (next[ch] == nullptr) next[ch] = new TrieNode();
                next[ch]->rchs |= (1<<rch);
                next[ch]->add(id, str, d+1);
            }
        }
        int search(string& pre, string& suf, int d=0) {
            int m = pre.length(), n = suf.length();
            if (this == nullptr) return -1;
            if (d-1>=0 && d-1<n) {
                int rch = suf[n-d] - 'a';
                if (!((rchs>>rch)&1)) return -1;
            }
            if (d>=m && d>=n && !ids.empty()) return ids.back();
            else {
                int res = -1;
                if (d < m) {
                    int ch = pre[d] - 'a';
                    res = max(res, next[ch]->search(pre, suf, d+1));
                }
                else for (int i=0; i<26; ++i) if (next[i] != nullptr) res = max(res, next[i]->search(pre, suf, d+1));
                return res;
            }
        }
    };
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
