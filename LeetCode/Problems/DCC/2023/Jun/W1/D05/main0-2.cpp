// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size(), xi = coordinates[1][0] - coordinates[0][0], yi = coordinates[1][1] - coordinates[0][1];
        for (int i=2; i<n; ++i) {
            int txi = coordinates[i][0] - coordinates[0][0], tyi = coordinates[i][1] - coordinates[0][1];
            if (xi*tyi != txi*yi) return false;
        }
        return true;
    }
};
