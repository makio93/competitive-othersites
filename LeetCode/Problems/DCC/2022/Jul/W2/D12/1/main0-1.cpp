// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum%4 != 0) return false;
        int tar = sum / 4;
        vector<int> vlst;
        for (int i=0; i<(1<<n); ++i) {
            int val = 0;
            for (int j=0; j<n; ++j) if (i&(1<<j)) val += matchsticks[j];
            if (val == tar) vlst.push_back(i);
        }
        int m = vlst.size();
        vector<int> dlst;
        for (int i=0; i<m; ++i) for (int j=i+1; j<m; ++j) if ((vlst[i]&vlst[j]) == 0) dlst.push_back(vlst[i]|vlst[j]);
        unordered_set<int> dst(dlst.begin(), dlst.end());
        int k = dlst.size(), msk = (1<<n) - 1;
        for (int i=0; i<k; ++i) {
            int ti = ~dlst[i] & msk;
            if (dst.find(ti) != dst.end()) return true;
        }
        return false;
    }
};
