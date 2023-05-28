// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> memo(m, vector<int>(m, -1));
        function<int(int,int)> f = [&](int li, int ri) {
            if (memo[li][ri] != -1) return memo[li][ri];
            if (ri < li) return memo[li][ri] = -INF;
            if (ri-li <= 1) return memo[li][ri] = 0;
            int rval = INF, slen = cuts[ri] - cuts[li];
            for (int mi=li+1; mi<ri; ++mi) rval = min(rval, f(li, mi) + f(mi, ri) + slen);
            return memo[li][ri] = rval;
        };
        return f(0, m-1);
    }
};
