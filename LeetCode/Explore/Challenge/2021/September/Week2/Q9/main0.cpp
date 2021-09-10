#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int m = mines.size();
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (int i=0; i<m; ++i) grid[mines[i][0]][mines[i][1]] = 0;
        vector<vector<vector<int>>> lcnt(2, vector<vector<int>>(n, vector<int>(n)));
        for (int i=0; i<n; ++i) {
            int l = -1, r = -1;
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    if (l == -1) {
                        l = r = j;
                        while (r+1<n && grid[i][r+1]==1) ++r;
                    }
                    lcnt[0][i][j] = min(j-l+1, r-j+1);
                }
                else l = r = -1;
            }
        }
        for (int i=0; i<n; ++i) {
            int u = -1, d = -1;
            for (int j=0; j<n; ++j) {
                if (grid[j][i] == 1) {
                    if (u == -1) {
                        u = d = j;
                        while (d+1<n && grid[d+1][i]==1) ++d;
                    }
                    lcnt[1][j][i] = min(j-u+1, d-j+1);
                }
                else u = d = -1;
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) res = max(res, min(lcnt[0][i][j], lcnt[1][i][j]));
        return res;
    }
};
