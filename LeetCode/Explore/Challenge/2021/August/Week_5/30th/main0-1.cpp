#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int len = ops.size();
        vector<int> aid, bid;
        aid.push_back(0); aid.push_back(m);
        bid.push_back(0); bid.push_back(n);
        for (int i=0; i<len; ++i) {
            aid.push_back(ops[i][0]);
            bid.push_back(ops[i][1]);
        }
        sort(aid.begin(), aid.end()); sort(bid.begin(), bid.end());
        aid.erase(unique(aid.begin(), aid.end()), aid.end());
        bid.erase(unique(bid.begin(), bid.end()), bid.end());
        int al = aid.size(), bl = bid.size();
        unordered_map<int, int> aidr, bidr;
        for (int i=0; i<al; ++i) aidr[aid[i]] = i;
        for (int i=0; i<bl; ++i) bidr[bid[i]] = i;
        vector<vector<int>> sub(al, vector<int>(bl));
        for (int i=0; i<len; ++i) {
            sub[aidr[0]][bidr[0]]++;
            sub[aidr[ops[i][0]]][bidr[ops[i][1]]]++;
            sub[aidr[ops[i][0]]][bidr[0]]--;
            sub[aidr[0]][bidr[ops[i][1]]]--;
        }
        for (int i=0; i<bl; ++i) for (int j=0; j<al-1; ++j) sub[j+1][i] += sub[j][i];
        for (int i=0; i<al; ++i) for (int j=0; j<bl-1; ++j) sub[i][j+1] += sub[i][j];
        int mval = 0, res = 0;
        for (int i=0; i<al; ++i) for (int j=0; j<bl; ++j) mval = max(mval, sub[i][j]);
        for (int i=0; i<al-1; ++i) for (int j=0; j<bl-1; ++j) if (sub[i][j] == mval) res += (aid[i+1] - aid[i]) * (bid[j+1] - bid[j]);
        return res;
    }
};
