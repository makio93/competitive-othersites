#include <bits/stdc++.h>
using namespace std;

// 本番終了後,自力AC

using ll = long long;
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size(), n = colCosts.size();
        vector<ll> rowSum(m+1), colSum(n+1);
        for (int i=0; i<m; ++i) rowSum[i+1] = rowSum[i] + rowCosts[i];
        for (int i=0; i<n; ++i) colSum[i+1] = colSum[i] + colCosts[i];
        ll res = rowSum[max(startPos[0],homePos[0])+1] - rowSum[min(startPos[0],homePos[0])]
             + colSum[max(startPos[1],homePos[1])+1] - colSum[min(startPos[1],homePos[1])]
             - rowCosts[startPos[0]] - colCosts[startPos[1]];
        return (int)res;
    }
};
