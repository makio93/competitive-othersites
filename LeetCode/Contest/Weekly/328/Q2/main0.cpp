// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<vector<int>> sub(n+1, vector<int>(n+1));
        for (int i=0; i<m; ++i) {
            sub[queries[i][0]][queries[i][1]]++;
            sub[queries[i][0]][queries[i][3]+1]--;
            sub[queries[i][2]+1][queries[i][1]]--;
            sub[queries[i][2]+1][queries[i][3]+1]++;
        }
        for (int i=0; i<n+1; ++i) for (int j=0; j<n; ++j) sub[j+1][i] += sub[j][i];
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) sub[i][j+1] += sub[i][j];
        for (int i=0; i<n; ++i) sub[i].resize(n);
        sub.resize(n);
        return sub;
    }
};
