// 自力WA2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<vector<int>> g(n);
        vector<int> din(n);
        for (int i=0; i<m; ++i) if (requests[i][0] != requests[i][1]) {
            g[requests[i][0]].push_back(requests[i][1]);
            din[requests[i][1]]++;
        }
        queue<int> que;
        int sub = 0;
        for (int i=0; i<n; ++i) if (din[i] == 0) que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            for (const int& ti : g[vi]) if (din[ti] > 0) {
                din[ti]--;
                ++sub;
                if (din[ti] == 0) que.push(ti);
            }
        }
        int res = m - sub;
        return res;
    }
};
