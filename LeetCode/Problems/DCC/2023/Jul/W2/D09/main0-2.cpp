// 自力TLE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int n = s.length(), res = 0;
        vector<vector<int>> ccnt(n+1, vector<int>(26));
        for (int i=0; i<n; ++i) {
            ccnt[i+1] = ccnt[i];
            ccnt[i+1][s[i]-'a']++;
        }
        function<int(int, int)> mfind = [&](int li, int ri) {
            int rval = 0;
            for (int i=0; i<26; ++i) for (int j=0; j<26; ++j) 
                if (ccnt[ri][i]-ccnt[li][i]>0 && ccnt[ri][j]-ccnt[li][j]>0) 
                    rval = max(rval, ccnt[ri][i]-ccnt[li][i]-ccnt[ri][j]+ccnt[li][j]);
            return rval;
        };
        for (int i=0; i<n; ++i) for (int j=i+1; j<=n; ++j) res = max(res, mfind(i, j));
        return res;
    }
};
