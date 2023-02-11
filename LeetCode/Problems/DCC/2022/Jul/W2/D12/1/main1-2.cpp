// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0), tar = sum / 4;
        if (tar*4 != sum) return false;
        unordered_map<int, bool> memo;
        int mask = (1<<n) - 1;
        auto dfs = [&](auto dfs, int bi=0) -> bool {
            if (memo.find(bi) != memo.end()) return memo[bi];
            int sval = 0;
            for (int i=0; i<n; ++i) if (bi&(1<<i)) sval += matchsticks[i];
            int cnt = sval / tar, rval = sval % tar;
            if (cnt == 3) return memo[bi] = true;
            for (int i=0; i<n; ++i) if (!(bi&(1<<i))) {
                if (rval+matchsticks[i] > tar) continue;
                if (dfs(dfs, bi|(1<<i))) return memo[bi] = true;
            }
            return memo[bi] = false;
        };
        return dfs(dfs);
    }
};
