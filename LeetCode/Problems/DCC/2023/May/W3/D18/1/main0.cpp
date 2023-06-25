// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> din(n);
        for (int i=0; i<m; ++i) din[edges[i][1]]++;
        vector<int> res;
        for (int i=0; i<n; ++i) if (din[i] == 0) res.push_back(i);
        return res;
    }
};
