// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode {
        bool leaf;
        vector<TrieNode*> next;
        TrieNode() {
            next.resize(26, nullptr);
            leaf = true;
        }
        TrieNode* next_node(int id) {
            if (next[id] == nullptr) {
                next[id] = new TrieNode();
                if (leaf) leaf = false;
            }
            return next[id];
        }
    };
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        TrieNode *root = new TrieNode();
        unordered_map<TrieNode*, int> nodes;
        for (int i=0; i<n; ++i) {
            auto cur = root;
            int len = words[i].length();
            for (int j=len-1; j>=0; --j) cur = cur->next_node(words[i][j]-'a');
            nodes[cur] = i;
        }
        int res = 0;
        for (const auto& pi : nodes) if (pi.first->leaf) res += words[pi.second].length() + 1;
        return res;
    }
};
