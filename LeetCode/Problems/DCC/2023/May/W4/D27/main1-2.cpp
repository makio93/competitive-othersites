// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> memo(n+1, -INF);
        function<int(int)> f = [&](int vi) {
            if (memo[vi] != -INF) return memo[vi];
            if (vi == n) return memo[vi] = 0;
            int sum = 0, rval = -INF;
            for (int i=0; i<3&&vi+i<n; ++i) {
                sum += stoneValue[vi+i];
                rval = max(rval, sum-f(vi+i+1));
            }
            return memo[vi] = rval;
        };
        return f(0) > 0 ? "Alice" : f(0) < 0 ? "Bob" : "Tie";
    }
};
