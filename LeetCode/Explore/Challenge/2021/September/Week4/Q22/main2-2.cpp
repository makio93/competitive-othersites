#include <bits/stdc++.h>
using namespace std;

// 解説AC2-2

class Solution {
    void enc(string word, unordered_set<int>& oset) {
        int sval = 0;
        for (char ci : word) {
            if ((sval>>(ci-'a'))&1) return;
            sval |= (1<<(ci-'a'));
        }
        sval += (word.length()<<26);
        oset.insert(sval);
    }
    int dfs(vector<int>& alst, int pos, int cset, int clen) {
        int res = clen;
        for (int i=pos; i<(int)(alst.size()); ++i) {
            if (alst[i] & cset) continue;
            res = max(res, dfs(alst, i+1, cset+(alst[i]&((1<<26)-1)), clen+(alst[i]>>26)));
        }
        return res;
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        unordered_set<int> oset;
        for (string word : arr) enc(word, oset);
        vector<int> alst(oset.begin(), oset.end());
        return dfs(alst, 0, 0, 0);
    }
};
