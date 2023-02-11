// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0), tar = sum / 4;
        if (tar*4 != sum) return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sums(4);
        auto dfs = [&](auto dfs, int vi=0) -> bool {
            if (vi == n) {
                for (int i=0; i<3; ++i) if (sums[i] != sums[i+1]) return false;
                return true;
            }
            for (int i=0; i<4; ++i) if (sums[i]+matchsticks[vi] <= tar) {
                sums[i] += matchsticks[vi];
                if (dfs(dfs, vi+1)) return true;
                sums[i] -= matchsticks[vi];
            }
            return false;
        };
        return dfs(dfs);
    }
};
