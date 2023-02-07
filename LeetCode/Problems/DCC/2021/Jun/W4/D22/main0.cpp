#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        vector<queue<int>> clst(26);
        for (int i=0; i<m; ++i) clst[words[i][0]-'a'].push(i);
        vector<int> wids(m);
        int res = 0;
        for (int i=0; i<n; ++i) {
            int clen = clst[s[i]-'a'].size();
            for (int j=0; j<clen; ++j) {
                int wi = clst[s[i]-'a'].front(); clst[s[i]-'a'].pop();
                wids[wi]++;
                if (wids[wi] >= words[wi].length()) {
                    ++res;
                    continue;
                }
                clst[words[wi][wids[wi]]-'a'].push(wi);
            }
        }
        return res;
    }
};
