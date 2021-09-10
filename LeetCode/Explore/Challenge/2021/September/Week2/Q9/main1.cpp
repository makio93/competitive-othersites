#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int m = mines.size();
        unordered_set<int> zeros;
        for (int i=0; i<m; ++i) zeros.insert(mines[i][0]*n+mines[i][1]);
        vector<vector<int>> mvals(n, vector<int>(n));
        int res = 0;
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) {
                if (zeros.find(i*n+j) != zeros.end()) cnt = 0;
                else ++cnt;
                mvals[i][j] = cnt;
            }
            cnt = 0;
            for (int j=n-1; j>=0; --j) {
                if (zeros.find(i*n+j) != zeros.end()) cnt = 0;
                else ++cnt;
                mvals[i][j] = min(mvals[i][j], cnt);
            }
        }
        for (int i=0; i<n; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) {
                if (zeros.find(j*n+i) != zeros.end()) cnt = 0;
                else ++cnt;
                mvals[j][i] = min(mvals[j][i], cnt);
            }
            cnt = 0;
            for (int j=n-1; j>=0; --j) {
                if (zeros.find(j*n+i) != zeros.end()) cnt = 0;
                else ++cnt;
                mvals[j][i] = min(mvals[j][i], cnt);
                res = max(res, mvals[j][i]);
            }
        }
        return res;
    }
};
