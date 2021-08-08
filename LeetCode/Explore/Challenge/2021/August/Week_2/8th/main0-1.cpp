#include <bits/stdc++.h>
using namespace std;

// 自力WA

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        vector<vector<pair<int, int>>> rows(n, vector<pair<int, int>>(m)), cols(m, vector<pair<int, int>>(n));
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) rows[i][j] = { matrix[i][j], j };
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) cols[i][j] = { matrix[j][i], j };
        vector<vector<int>> res(n, vector<int>(m));
        for (int i=0; i<n; ++i) {
            sort(rows[i].begin(), rows[i].end());
            int rval = 1;
            for (int j=0; j<m; ++j) {
                if (j-1>=0 && rows[i][j-1].first<rows[i][j].first) ++rval;
                res[i][rows[i][j].second] = rval;
            }
        }
        for (int i=0; i<m; ++i) sort(cols[i].begin(), cols[i].end());
        vector<int> bias(n), bias2(m);
        while (1) {
            bool fin = true;
            for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                    if (j+1<n && cols[i][j].first==cols[i][j+1].first) {
                        if (res[cols[i][j+1].second][i]+bias[cols[i][j+1].second] != res[cols[i][j].second][i]+bias[cols[i][j].second]) fin = false;
                        bias[cols[i][j].second] += max(0, (res[cols[i][j+1].second][i]+bias[cols[i][j+1].second])-(res[cols[i][j].second][i]+bias[cols[i][j].second]));
                    }
                    if (j-1 >= 0) {
                        if (cols[i][j-1].first == cols[i][j].first) 
                            bias[cols[i][j].second] += max(0, (res[cols[i][j-1].second][i]+bias[cols[i][j-1].second])-(res[cols[i][j].second][i]+bias[cols[i][j].second]));
                        else if (cols[i][j-1].first < cols[i][j].first) {
                            if (res[cols[i][j-1].second][i]+bias[cols[i][j-1].second] > res[cols[i][j].second][i]+bias[cols[i][j].second]+1) fin = false;
                            bias[cols[i][j].second] += max(0, (res[cols[i][j-1].second][i]+bias[cols[i][j-1].second])-(res[cols[i][j].second][i]+bias[cols[i][j].second])+1);
                        }
                    }
                }
            }
            for (int i=0; i<n; ++i) {
                for (int j=0; j<m; ++j) {
                    if (j+1<m && rows[i][j].first==rows[i][j+1].first) {
                        if (res[rows[i][j+1].second][i]+bias[rows[i][j+1].second] != res[rows[i][j].second][i]+bias[rows[i][j].second]) fin = false;
                        bias2[rows[i][j].second] += max(0, (res[rows[i][j+1].second][i]+bias[rows[i][j+1].second])-(res[rows[i][j].second][i]+bias[rows[i][j].second]));
                    }
                    if (j-1 >= 0) {
                        if (rows[i][j-1].first == rows[i][j].first) 
                            bias2[rows[i][j].second] += max(0, (res[rows[i][j-1].second][i]+bias[rows[i][j-1].second])-(res[rows[i][j].second][i]+bias[rows[i][j].second]));
                        else if (rows[i][j-1].first < rows[i][j].first) {
                            if (res[rows[i][j-1].second][i]+bias[rows[i][j-1].second] > res[rows[i][j].second][i]+bias[rows[i][j].second]+1) fin = false;
                            bias2[rows[i][j].second] += max(0, (res[rows[i][j-1].second][i]+bias[rows[i][j-1].second])-(res[rows[i][j].second][i]+bias[rows[i][j].second])+1);
                        }
                    }
                }
            }
            if (fin) break;
        }
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) res[i][j] += bias[i] + bias2[j];
        return res;
    }
};
