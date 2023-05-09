// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
const vector<int> dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix.front().size(), dir = 0, yi = 0, xi = 0;
        vector<int> res;
        while ((int)(res.size()) < m*n) {
            if (matrix[yi][xi] != -INF) {
                res.push_back(matrix[yi][xi]);
                matrix[yi][xi] = -INF;
            }
            else {
                int pdir = dir;
                do {
                    int nyi = yi + dy[dir], nxi = xi + dx[dir];
                    if (nyi>=0 && nyi<m && nxi>=0 && nxi<n && matrix[nyi][nxi]!=-INF) {
                        yi = nyi, xi = nxi;
                        break;
                    }
                    dir = (dir + 1) % 4;
                } while (dir != pdir);
            }
        }
        return res;
    }
};
