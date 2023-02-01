// 本番AC

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int score;
    vector<TrieNode*> next;
    TrieNode() : score(0), next(26, nullptr) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() : root(new TrieNode()) {}
    void add(string& str) {
        int len = str.length();
        auto node = root;
        for (int i=0; i<len; ++i) {
            if (node->next[str[i]-'a'] == nullptr) node->next[str[i]-'a'] = new TrieNode();
            node = node->next[str[i]-'a'];
            node->score++;
        }
    }
    int value(string& str) {
        int len = str.length(), res = 0;
        auto node = root;
        for (int i=0; i<len; ++i) {
            if (node->next[str[i]-'a'] == nullptr) return res;
            node = node->next[str[i]-'a'];
            res += node->score;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie tr;
        for (int i=0; i<n; ++i) tr.add(words[i]);
        vector<int> res(n);
        for (int i=0; i<n; ++i) res[i] = tr.value(words[i]);
        return res;
    }
};
