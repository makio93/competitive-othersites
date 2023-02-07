#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts.front().size(), res = 0;
        for (int i=0; i<m; ++i) {
            int sum = 0;
            for (int j=0; j<n; ++j) sum += accounts[i][j];
            res = max(res, sum);
        }
        return res;
    }
};
