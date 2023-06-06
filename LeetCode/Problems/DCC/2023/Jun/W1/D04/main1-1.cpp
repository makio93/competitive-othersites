// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int res = 0;
        for (int i=0; i<n; ++i) if (visited[i] == 0) {
            ++res;
            function<void(int)> dfs = [&](int vi) {
                visited[vi] = res;
                for (int ti=0; ti<n; ++ti) if (isConnected[vi][ti] == 1 && visited[ti] == 0) dfs(ti);
            };
            dfs(i);
        }
        return res;
    }
};
