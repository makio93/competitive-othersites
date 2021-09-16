#include <bits/stdc++.h>
using namespace std;

// 解説AC2

class Solution {
    const int VIS = 101;
    const vector<vector<int>> dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix.front().size();
        int ccnt = 0, cdir = 0, y = 0, x = 0;
        vector<int> res;
        res.push_back(matrix[y][x]);
        matrix[y][x] = VIS;
        while (ccnt < 2) {
            int ny = y + dir[cdir][0], nx = x + dir[cdir][1];
            while (ny>=0&&ny<n&&nx>=0&&nx<m&&matrix[ny][nx]!=VIS) {
                ccnt = 0;
                res.push_back(matrix[ny][nx]);
                matrix[ny][nx] = VIS;
                y = ny; x = nx;
                ny = y + dir[cdir][0]; nx = x + dir[cdir][1];
            }
            cdir = (cdir + 1) % 4;
            ++ccnt;
        }
        return res;
    }
};
