#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land.front().size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> res;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (!visited[i][j] && land[i][j]==1) {
            int i2 = i, j2 = j;
            while (j2+1<n && land[i][j2+1]==1) ++j2;
            while (i2+1<m && land[i2+1][j2]==1) ++i2;
            res.push_back({i, j, i2, j2});
            for (int i3=i; i3<=i2; ++i3) for (int j3=j; j3<=j2; ++j3) visited[i3][j3] = true;
        }
        return res;
    }
};
