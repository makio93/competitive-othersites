// 解説AC1

#include <bits/stdc++.h>
using namespace std;

struct Trie {
    int val;
    unordered_map<int, Trie*> next;
    Trie() : val(0) {}
};

const char nc = 'z' + 1;
class WordFilter {
    Trie *tree;
public:
    WordFilter(vector<string>& words) {
        tree = new Trie();
        int n = words.size();
        for (int i=0; i<n; ++i) {
            int m = words[i].length();
            Trie *cur = tree;
            for (int j=0; j<m; ++j) {
                Trie *tmp = cur;
                for (int i2=m-j-1; i2>=0; --i2) {
                    int cid = (nc-'a') * 27 + (words[i][i2]-'a');
                    if (tmp->next.find(cid) == tmp->next.end()) tmp->next[cid] = new Trie();
                    tmp = tmp->next[cid];
                    tmp->val = i;
                }
                tmp = cur;
                for (int i2=j; i2<m; ++i2) {
                    int cid = (words[i][i2]-'a') * 27 + (nc-'a');
                    if (tmp->next.find(cid) == tmp->next.end()) tmp->next[cid] = new Trie();
                    tmp = tmp->next[cid];
                    tmp->val = i;
                }
                int cid = (words[i][j]-'a') * 27 + (words[i][m-j-1]-'a');
                if (cur->next.find(cid) == cur->next.end()) cur->next[cid] = new Trie();
                cur = cur->next[cid];
                cur->val = i;
            }
        }
    }
    int f(string prefix, string suffix) {
        Trie *cur = tree;
        int n = prefix.length(), m = suffix.length();
        for (int i=0,j=0; i<n||j<m; ++i,++j) {
            int cid = (i<n ? prefix[i]-'a' : nc-'a') * 27 + (j<m ? suffix[m-j-1]-'a' : nc-'a');
            if (cur->next.find(cid) == cur->next.end()) return -1;
            cur = cur->next[cid];
        }
        return cur->val;
    }
};
