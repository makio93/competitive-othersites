// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> scnt;
        for (int i=0; i<n; ++i) {
            string si;
            for (int j=0; j<n; ++j) {
                si += to_string(grid[i][j]);
                if (j < n-1) si += ',';
            }
            scnt[si]++;
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            string si;
            for (int j=0; j<n; ++j) {
                si += to_string(grid[j][i]);
                if (j < n-1) si += ',';
            }
            if (scnt.find(si) != scnt.end()) res += scnt[si];
        }
        return res;
    }
};
