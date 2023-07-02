// 自力WA1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<int> up(n), down(n);
        for (int i=0; i<m; ++i) {
            down[requests[i][0]]++;
            up[requests[i][1]]++;
        }
        int res = 0;
        for (int i=0; i<n; ++i) res += min(up[i], down[i]);
        return res;
    }
};
