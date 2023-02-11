// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum%4 != 0) return false;
        int tar = sum / 4;
        vector<bool> used(n);
        auto dfs = [&](auto dfs, int vi=0, int di=0, int val=0) -> bool {
            if (val > tar) return false;
            if (val == tar) {
                if (di == 3) return true;
                else return dfs(dfs, vi=0, di+1, 0);
            }
            int ti = vi;
            if (vi == 0) {
                while (ti<n && used[ti]) ++ti;
                if (ti == n) return false;
                used[ti] = true;
                if (dfs(dfs, ti+1, di, val+matchsticks[ti])) return true;
                used[ti] = false;
                return false;
            }
            else {
                while (ti < n) {
                    if (!used[ti]) {
                        used[ti] = true;
                        if (dfs(dfs, ti+1, di, val+matchsticks[ti])) return true;
                        used[ti] = false;
                    }
                    ++ti;
                }
                return false;
            }
        };
        return dfs(dfs);
    }
};
