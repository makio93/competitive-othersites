// 自力AC

#include <bits/stdc++.h>
using namespace std;

const vector<int> dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int val = 1, yi = 0, xi = 0, di = 0;
        while (val <= n*n) {
            if (res[yi][xi] == 0) res[yi][xi] = val++;
            else {
                int nyi = yi + dy[di], nxi = xi + dx[di];
                if (nyi>=0 && nyi<n && nxi>=0 && nxi<n && res[nyi][nxi]==0) yi = nyi, xi = nxi;
                else di = (di + 1) % 4;
            }
        }
        return res;
    }
};
