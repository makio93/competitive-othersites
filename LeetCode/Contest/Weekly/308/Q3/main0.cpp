// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const string tar = "MPG";
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<vector<int>> gcnt(3, vector<int>(n));
        vector<int> tvals(n), mvals(3);
        for (int i=0; i<3; ++i) {
            for (int j=0; j<n; ++j) {
                gcnt[i][j] = count(garbage[j].begin(), garbage[j].end(), tar[i]);
                if ((int)(count(garbage[j].begin(), garbage[j].end(), tar[i])) > 0) mvals[i] = max(mvals[i], j);
            }
            for (int j=0; j<n-1; ++j) gcnt[i][j+1] += gcnt[i][j];
        }
        for (int i=0; i<n-1; ++i) tvals[i+1] = tvals[i] + travel[i];
        int res = 0;
        for (int i=0; i<3; ++i) res += gcnt[i][mvals[i]] + tvals[mvals[i]];
        return res;
    }
};
