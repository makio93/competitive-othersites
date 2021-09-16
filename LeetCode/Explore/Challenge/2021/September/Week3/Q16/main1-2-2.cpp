#include <bits/stdc++.h>
using namespace std;

// 解説AC2-2

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
            while (y+dir[cdir][0]>=0&&y+dir[cdir][0]<n&&
                x+dir[cdir][1]>=0&&x+dir[cdir][1]<m&&
                matrix[y+dir[cdir][0]][x+dir[cdir][1]]!=VIS) {
                ccnt = 0;
                res.push_back(matrix[y+dir[cdir][0]][x+dir[cdir][1]]);
                matrix[y+dir[cdir][0]][x+dir[cdir][1]] = VIS;
                y = y+dir[cdir][0]; x = x+dir[cdir][1];
            }
            cdir = (cdir + 1) % 4;
            ++ccnt;
        }
        return res;
    }
};
