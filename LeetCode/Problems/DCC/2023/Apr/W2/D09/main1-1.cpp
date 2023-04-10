// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length(), m = edges.size();
        vector<vector<int>> g(n);
        vector<int> din(n);
        for (int i=0; i<m; ++i) {
            g[edges[i][0]].push_back(edges[i][1]);
            din[edges[i][1]]++;
        }
        vector<vector<int>> ccnt(n, vector<int>(26));
        int vcnt = 0, res = 0;
        queue<int> que;
        for (int i=0; i<n; ++i) if (din[i] == 0) que.push(i);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            ++vcnt;
            ccnt[vi][colors[vi]-'a']++;
            res = max(res, ccnt[vi][colors[vi]-'a']);
            for (const int& ti : g[vi]) {
                din[ti]--;
                for (int i=0; i<26; ++i) ccnt[ti][i] = max(ccnt[ti][i], ccnt[vi][i]);
                if (din[ti] == 0) que.push(ti);
            }
        }
        return vcnt < n ? -1 : res;
    }
};
