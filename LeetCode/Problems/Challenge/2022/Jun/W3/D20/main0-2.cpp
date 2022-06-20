// 自力AC2

#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<Node*> next;
    Node() : next(26, NULL) {}
    void insert(string& word, int di=0) {
        if (di >= (int)(word.length())) return;
        if (next[word[word.length()-di-1]-'a'] == NULL) next[word[word.length()-di-1]-'a'] = new Node();
        next[word[word.length()-di-1]-'a']->insert(word, di+1);
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        Node* root = new Node();
        for (int i=0; i<n; ++i) root->insert(words[i]);
        auto dfs = [&](auto dfs, Node* cur, int di=0) -> int {
            int val = 0;
            bool tail = true;
            for (int i=0; i<26; ++i) if (cur->next[i] != NULL) {
                tail = false;
                val += dfs(dfs, cur->next[i], di+1);
            }
            if (tail) val += di+1;
            return val;
        };
        return dfs(dfs, root);
    }
};
