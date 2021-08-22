#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    const long long mod = (long long)(1e9) + 7;
    const int INF = (int)(1e9) + 5;
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<int> xret, yret;
        xret.push_back(INF);
        yret.push_back(INF);
        for (int i=0; i<n; ++i) {
            xret.push_back(rectangles[i][0]);
            xret.push_back(rectangles[i][2]);
            yret.push_back(rectangles[i][1]);
            yret.push_back(rectangles[i][3]);
        }
        sort(xret.begin(), xret.end());
        sort(yret.begin(), yret.end());
        xret.erase(unique(xret.begin(), xret.end()), xret.end());
        yret.erase(unique(yret.begin(), yret.end()), yret.end());
        unordered_map<int, int> xto, yto;
        for (int i=0; i<(int)(xret.size()); ++i) xto[xret[i]] = i;
        for (int i=0; i<(int)(yret.size()); ++i) yto[yret[i]] = i;
        int r2 = yret.size(), c2 = xret.size();
        vector<vector<int>> sub(r2, vector<int>(c2));
        for (int i=0; i<n; ++i) {
            sub[yto[rectangles[i][1]]][xto[rectangles[i][0]]]++;
            sub[yto[rectangles[i][3]]][xto[rectangles[i][0]]]--;
            sub[yto[rectangles[i][1]]][xto[rectangles[i][2]]]--;
            sub[yto[rectangles[i][3]]][xto[rectangles[i][2]]]++;
        }
        for (int i=0; i<r2; ++i) for (int j=0; j+1<c2; ++j) sub[i][j+1] += sub[i][j];
        for (int i=0; i<c2; ++i) for (int j=0; j+1<r2; ++j) sub[j+1][i] += sub[j][i];
        long long res = 0;
        for (int i=0; i+1<r2; ++i) for (int j=0; j+1<c2; ++j) {
            long long area = (long long)(yret[i+1] - yret[i]) * (xret[j+1] - xret[j]);
            res += area * min(1, sub[i][j]);
        }
        return (int)(res % mod);
    }
};
