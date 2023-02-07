#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int tar = 0;
        for (int i=0; i<n; ++i) tar += matchsticks[i];
        if (tar%4 != 0) return false;
        tar /= 4;
        for (int i=1; i<(1<<n)-1; ++i) {
            vector<vector<int>> lsts(2);
            vector<int> sums(2);
            for (int j=0; j<n; ++j) {
                lsts[(i>>j)&1].push_back(matchsticks[j]);
                sums[(i>>j)&1] += matchsticks[j];
            }
            if (sums[0] != sums[1]) continue;
            vector<set<int>> vals(2, set<int>({0}));
            bool ok = true;
            for (int i=0; i<2; ++i) {
                for (int add : lsts[i]) for (auto itr=vals[i].rbegin(); itr!=vals[i].rend(); ++itr) vals[i].insert(*itr+add);
                if (vals[i].find(tar) == vals[i].end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
    }
};
