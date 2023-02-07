#include <bits/stdc++.h>
using namespace std;

// 自力AC

class WordDictionary {
    struct charNode {
        vector<charNode*> next;
        charNode(int len=26) : next(len, nullptr) {}
    };
    int n;
    vector<charNode*> dict;
public:
    WordDictionary(int _n=500) {
        n = _n;
        dict = vector<charNode*>(n, nullptr);
        for (int i=0; i<n; ++i) dict[i] = new charNode;
    }
    void addWord(string word) {
        int len = word.length();
        auto ptr = dict[len-1];
        for (int i=0; i<len; ++i) {
            if (ptr->next[word[i]-'a'] == nullptr) ptr->next[word[i]-'a'] = new charNode;
            ptr = ptr->next[word[i]-'a'];
        }
    }
    bool search(string word) {
        int len = word.length();
        stack<pair<charNode*, int>> dfs;
        dfs.emplace(dict[len-1], 0);
        while (!dfs.empty()) {
            auto [ptr, pos] = dfs.top(); dfs.pop();
            if (word[pos] == '.') {
                for (int i=0; i<26; ++i) if (ptr->next[i] != nullptr) {
                    if (pos+1 == len) return true;
                    else dfs.emplace(ptr->next[i], pos+1);
                }
            }
            else if (ptr->next[word[pos]-'a'] != nullptr) {
                if (pos+1 == len) return true;
                else dfs.emplace(ptr->next[word[pos]-'a'], pos+1);
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
