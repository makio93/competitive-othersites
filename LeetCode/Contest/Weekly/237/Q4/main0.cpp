#include <bits/stdc++.h>
using namespace std;

// 本番WA

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        vector<vector<int>> bcnt1(n, vector<int>(31));
        vector<int> bsum2(31), bres(31);
        for (int i=0; i<n; ++i) {
            int ai = arr1[i], id = 0;
            while (ai > 0) {
                if ((ai&1)) bcnt1[i][id]++;
                ai >>= 1;
                ++id;
            }
        }
        for (int i=0; i<m; ++i) {
            int ai = arr2[i], id = 0;
            vector<int> tsum2(31);
            while (ai > 0) {
                if ((ai&1)) tsum2[id]++;
                ai >>= 1;
                ++id;
            }
            for (int j=0; j<31; ++j) bsum2[j] += tsum2[j];
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<31; ++j) bres[j] += bsum2[j];
            for (int j=0; j<31; ++j) bres[j] += bcnt1[i][j] * m;
        }
        for (int i=0; i<31; ++i) bres[i] %= 2;
        int res = 0;
        for (int i=1; i<31; ++i) res += (1<<(i-1))*bres[i];
        return res;
    }
};
