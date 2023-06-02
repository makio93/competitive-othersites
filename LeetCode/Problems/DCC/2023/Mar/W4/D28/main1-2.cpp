// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> lens = { 1, 7, 30 }, memo(n+1, -1);
        function<int(int)> dp = [&](int vi) {
            vi = min(vi, n);
            if (memo[vi] != -1) return memo[vi];
            if (vi == n) return memo[vi] = 0;
            int ti = vi + 1, rval = INF;
            for (int i1=0; i1<3; ++i1) {
                while (ti<n && days[ti]<days[vi]+lens[i1]) ++ti;
                rval = min(rval, dp(ti)+costs[i1]);
            }
            return memo[vi] = rval;
        };
        return dp(0);
    }
};
