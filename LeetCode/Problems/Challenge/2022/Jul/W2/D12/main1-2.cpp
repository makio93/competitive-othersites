// 解説2,AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(), tar = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (tar%4 != 0) return false;
        tar /= 4;
        map<pair<int, int>, bool> memo;
        auto dfs = [&](auto dfs, int mlst, int scnt=0) -> bool {
            if (memo.find({ mlst, scnt }) != memo.end()) return memo[{ mlst, scnt }];
            int sum = 0;
            for (int i=0; i<n; ++i) if (!((mlst>>i)&1)) sum += matchsticks[i];
            if (sum>0 && sum%tar==0) ++scnt;
            if (scnt == 3) return memo[{ mlst, scnt }] = true;
            int mval = (sum/tar+1)*tar - sum;
            for (int i=0; i<n; ++i) if (((mlst>>i)&1) && matchsticks[i]<=mval) {
                if (dfs(dfs, mlst^(1<<i), scnt)) return memo[{ mlst, scnt }] = true;
            }
            return memo[{ mlst, scnt }] = false;
        };
        return dfs(dfs, (1<<n)-1);
    }
};
