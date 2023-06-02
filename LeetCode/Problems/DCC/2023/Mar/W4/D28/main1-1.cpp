// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        unordered_set<int> dst;
        for (int i=0; i<n; ++i) dst.insert(days[i]);
        vector<int> memo(367, -1);
        function<int(int)> dp = [&](int di) {
            di = min(di, 366);
            if (memo[di] != -1) return memo[di];
            if (di > 365) return memo[di] = 0;
            if (dst.find(di) == dst.end()) return memo[di] = dp(di+1);
            return memo[di] = min({ dp(di+1)+costs[0], dp(di+7)+costs[1], dp(di+30)+costs[2] });
        };
        return dp(1);
    }
};
