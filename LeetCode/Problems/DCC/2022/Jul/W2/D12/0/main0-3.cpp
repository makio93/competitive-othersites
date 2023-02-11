// 自力TLE3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int tar = 0;
        for (int val : matchsticks) tar += val;
        if (tar%4 != 0) return false;
        tar /= 4;
        vector<int> vals(4);
        multiset<int> fst;
        set<multiset<int>> memo;
        auto dfs = [&](auto dfs, int di=0) -> bool {
            if (memo.find(fst) != memo.end()) return false;
            if (di == n) return true;
            for (int id=0; id<4; ++id) if (vals[id]+matchsticks[di] <= tar) {
                fst.erase(fst.find(vals[id]));
                vals[id] += matchsticks[di];
                fst.insert(vals[id]);
                if (dfs(dfs, di+1)) return true;
                fst.erase(fst.find(vals[id]));
                vals[id] -= matchsticks[di];
                fst.insert(vals[id]);
            }
            memo.insert(fst);
            return false;
        };
        for (int i=0; i<4; ++i) fst.insert(0);
        return dfs(dfs);
    }
};
