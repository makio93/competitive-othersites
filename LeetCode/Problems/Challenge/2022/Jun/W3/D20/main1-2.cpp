// 解説AC2

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int cnt;
    vector<TrieNode*> next;
    TrieNode() : cnt(0), next(26, NULL) {}
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*, int> tids;
        for (int i=0; i<n; ++i) {
            int m = words[i].length();
            TrieNode* cur = trie;
            for (int j=m-1; j>=0; --j) {
                if (cur->next[words[i][j]-'a'] == NULL) {
                    cur->next[words[i][j]-'a'] = new TrieNode();
                    cur->cnt++;
                }
                cur = cur->next[words[i][j]-'a'];
            }
            tids[cur] = i;
        }
        int res = 0;
        for (auto& pi : tids) if (pi.first->cnt == 0) res += words[pi.second].length() + 1;
        return res;
    }
};
