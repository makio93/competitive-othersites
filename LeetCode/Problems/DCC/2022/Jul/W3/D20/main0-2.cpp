// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        vector<int> wps(m);
        vector<queue<int>> wids(26);
        for (int i=0; i<m; ++i) wids[words[i][0]-'a'].push(i);
        int res = 0;
        for (const char& ci : s) {
            int qlen = wids[ci-'a'].size();
            while (qlen--) {
                int id = wids[ci-'a'].front(); wids[ci-'a'].pop();
                wps[id]++;
                if (wps[id] >= (int)(words[id].length())) ++res;
                else wids[words[id][wps[id]]-'a'].push(id);
            }
        }
        return res;
    }
};
