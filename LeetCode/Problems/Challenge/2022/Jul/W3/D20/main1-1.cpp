// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length(), m = words.size();
        vector<vector<pair<int, int>>> wids(26);
        for (int i=0; i<m; ++i) wids[words[i][0]-'a'].emplace_back(i, 0);
        int res = 0;
        for (const char& ci : s) {
            auto tmp = wids[ci-'a'];
            wids[ci-'a'].clear();
            for (auto pi : tmp) {
                if (pi.second+1 >= (int)words[pi.first].length()) ++res;
                else wids[words[pi.first][pi.second+1]-'a'].emplace_back(pi.first, pi.second+1);
            }
        }
        return res;
    }
};
