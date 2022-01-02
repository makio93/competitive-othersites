#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank.front().length();
        vector<int> bcnt;
        for (int i=0; i<m; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) if (bank[i][j] == '1') ++cnt;
            if (cnt > 0) bcnt.push_back(cnt);
        }
        int res = 0;
        for (int i=1; i<(int)(bcnt.size()); ++i) res += bcnt[i-1] * bcnt[i];
        return res;
    }
};
