// 自力TLE1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        vector<int> svals(4);
        auto dfs = [&](auto dfs, int di=0, int si=0) -> bool {
            if (di == n) {
                if (si < 4) return false;
                for (int id=1; id<4; ++id) if (svals[id] != svals[0]) return false;
                return true;
            }
            for (int id=0; id<min(si+1,4); ++id) {
                svals[id] += matchsticks[di];
                if (id==si && dfs(dfs,di+1,si+1)) return true;
                if (id<si && dfs(dfs,di+1,si)) return true;
                svals[id] -= matchsticks[di];
            }
            return false;
        };
        return dfs(dfs);
    }
};
