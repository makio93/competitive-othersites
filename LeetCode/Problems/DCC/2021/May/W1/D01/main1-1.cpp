#include <bits/stdc++.h>
using namespace std;

// Discuss解1,TLEする

class Trie {
    vector<int> ids;
    vector<Trie*> next;
public:
    Trie() : next(26, nullptr) {}
    ~Trie() { for (int i=0; i<26; ++i) if (next[i] != nullptr) delete next[i]; }
    void add(const string& word, size_t bid, int id) {
        ids.push_back(id);
        if (bid < word.length()) {
            if (next[word[bid]-'a'] == nullptr) next[word[bid]-'a'] = new Trie();
            next[word[bid]-'a']->add(word, bid+1, id);
        }
    }
    vector<int> search(const string& pre, size_t bid) {
        if (bid == pre.length()) return ids;
        else {
            if (next[pre[bid]-'a'] != nullptr) return next[pre[bid]-'a']->search(pre, bid+1);
            else return vector<int>({});
        }
    }
};

class WordFilter {
    Trie *forwards, *backwards;
public:
    WordFilter(vector<string>& words) {
        int n = words.size();
        forwards = new Trie();
        backwards = new Trie();
        for (int i=0; i<n; ++i) {
            string ws = words[i];
            forwards->add(ws, 0, i);
            reverse(ws.begin(), ws.end());
            backwards->add(ws, 0, i);
        }
    }
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        auto flst = forwards->search(prefix, 0), blst = backwards->search(suffix, 0);
        int fid = flst.size()-1, bid = blst.size()-1;
        while (fid>=0 && bid>=0) {
            if (flst[fid] == blst[bid]) return flst[fid];
            else if (flst[fid] > blst[bid]) --fid;
            else --bid;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
