// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        vector<int> wps(m);
        vector<unordered_set<int>> wids(26);
        unordered_set<int> tids;
        for (int i=0; i<m; ++i) wids[words[i][0]-'a'].insert(i);
        int res = 0;
        for (const char& ci : s) if (!wids[ci-'a'].empty()) {
            tids = wids[ci-'a'];
            wids[ci-'a'].clear();
            for (const int& id : tids) {
                wps[id]++;
                if (wps[id] >= (int)(words[id].length())) ++res;
                else wids[words[id][wps[id]]-'a'].insert(id);
            }
        }
        return res;
    }
};
