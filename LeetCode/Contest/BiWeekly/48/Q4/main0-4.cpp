// 自力AC

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gvals(n, vector<int>(n));
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) gvals[i][j] = gcd(nums[i], nums[j]);
        vector<int> memo(1<<n, -1);
        function<int(int,int)> dfs = [&](int di, int blst) {
            if (memo[blst] != -1) return memo[blst];
            if (di == n/2) return memo[blst] = 0;
            else {
                int res = 0;
                for (int li=0; li<n; ++li) if (!((blst>>li)&1)) {
                    blst |= 1<<li;
                    for (int ri=li+1; ri<n; ++ri) if (!((blst>>ri)&1)) {
                        blst |= 1<<ri;
                        res = max(res, gvals[li][ri] * (n/2-di) + dfs(di+1, blst));
                        blst ^= 1<<ri;
                    }
                    blst ^= 1<<li;
                }
                return memo[blst] = res;
            }
        };
        return dfs(0, 0);
    }
};
