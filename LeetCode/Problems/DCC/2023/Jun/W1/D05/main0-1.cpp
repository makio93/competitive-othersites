// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        sort(coordinates.begin(), coordinates.end());
        int dx = coordinates[1][0] - coordinates[0][0], dy = coordinates[1][1] - coordinates[0][1];
        if (dx == 0) {
            dy /= abs(dy);
            for (int i=1; i<n; ++i) if (coordinates[i][0] != coordinates[0][0]) return false;
            return true;
        }
        if (dy == 0) dx /= abs(dx);
        else {
            int gval = gcd(abs(dx), abs(dy));
            dx /= gval;
            dy /= gval;
        }
        for (int i=1; i<n-1; ++i) if ((coordinates[i+1][0]-coordinates[i][0])%dx!=0 || coordinates[i][1]+(coordinates[i+1][0]-coordinates[i][0])/dx*dy!=coordinates[i+1][1]) return false;
        return true;
    }
};