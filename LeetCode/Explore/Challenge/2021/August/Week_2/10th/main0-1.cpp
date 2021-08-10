#include <bits/stdc++.h>
using namespace std;

// 自力AC1

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>> lcnt(n+1, vector<int>(2)), rcnt(n+1, vector<int>(2));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<2; ++j) lcnt[i+1][j] += lcnt[i][j];
            lcnt[i+1][s[i]-'0']++;
        }
        for (int i=n-1; i>=0; --i) {
            for (int j=0; j<2; ++j) rcnt[i][j] += rcnt[i+1][j];
            rcnt[i][s[i]-'0']++;
        }
        int res = n;
        for (int i=0; i<n; ++i) for (int j=0; j<(1<<2); ++j) if (j != 1) {
            res = min(res, lcnt[i][(j>>1)&1]+rcnt[i][j&1]);
        }
        return res;
    }
};
