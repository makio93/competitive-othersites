// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size(), res = 0;
        for (int i=0; i<1<<m; ++i) {
            vector<int> rcnt(n);
            for (int j=0; j<m; ++j) if (i>>j&1) {
                rcnt[requests[j][0]]--;
                rcnt[requests[j][1]]++;
            }
            bool ok = true;
            for (int j=0; j<n; ++j) if (rcnt[j] != 0) ok = false;
            if (ok) res = max(res, __builtin_popcount(i));
        }
        return res;
    }
};
