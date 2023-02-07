// 解説AC2

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    int val;
    vector<Trie*> next;
    Trie() : val(0), next(27, NULL) {}
};

class WordFilter {
    Trie *tree;
public:
    WordFilter(vector<string>& words) {
        tree = new Trie();
        int n = words.size();
        for (int i1=0; i1<n; ++i1) {
            int m = words[i1].length();
            string tar = words[i1] + (char)('z'+1) + words[i1];
            for (int i=0; i<m; ++i) {
                Trie *cur = tree;
                for (int j=i; j<2*m+1; ++j) {
                    if (cur->next[tar[j]-'a'] == NULL) cur->next[tar[j]-'a'] = new Trie();
                    cur = cur->next[tar[j]-'a'];
                    cur->val = i1;
                }
            }
        }
    }
    int f(string prefix, string suffix) {
        string tar = suffix + (char)('z'+1) + prefix;
        int m = tar.length();
        Trie *cur = tree;
        for (int i=0; i<m; ++i) {
            if (cur->next[tar[i]-'a'] == NULL) return -1;
            cur = cur->next[tar[i]-'a'];
        }
        return cur->val;
    }
};
