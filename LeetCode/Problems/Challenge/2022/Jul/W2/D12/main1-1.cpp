// 解説1,TLE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), tar = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (tar%4 != 0) return false;
        tar /= 4;
        vector<int> sums(4);
        auto dfs = [&](auto dfs, int id=0) -> bool {
            if (id == n) {
                for (int i=0; i<3; ++i) if (sums[i+1] != sums[i]) return false;
                return true;
            }
            for (int i=0; i<4; ++i) if (sums[i]+matchsticks[id] <= tar) {
                sums[i] += matchsticks[id];
                if (dfs(dfs, id+1)) return true;
                sums[i] -= matchsticks[id];
            }
            return false;
        };
        return dfs(dfs);
    }
};
