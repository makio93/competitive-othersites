// 解説AC2

#include <bits/stdc++.h>
using namespace std;

array<array<int, 2>, 4> dif = { 0, 1, 1, 0, 0, -1, -1, 0 };
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int val = 1, yi = 0, xi = 0, di = 0;
        while (val <= n*n) {
            res[yi][xi] = val++;
            int nyi = yi + dif[di][0], nxi = xi + dif[di][1];
            if (nyi<0 || nyi>=n || nxi<0 || nxi>=n || res[nyi][nxi]!=0) {
                di = (di + 1) % 4;
                nyi = yi + dif[di][0], nxi = xi + dif[di][1];
            }
            yi = nyi, xi = nxi;
        }
        return res;
    }
};
