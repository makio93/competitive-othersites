// 終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> mcnt(k);
        for (int i=0; i<n; ++i) mcnt[i%k][nums[i]]++;
        vector<vector<int>> memo(1<<10, vector<int>(k, -1));
        auto dfs = [&](auto dfs, int tar=0, int ki=0) -> int {
            if (memo[tar][ki] != -1) return memo[tar][ki];
            if (ki == k-1) {
                if (mcnt[ki].find(tar) != mcnt[ki].end()) return memo[tar][ki] = mcnt[ki][tar];
                else return memo[tar][ki] = 0;
            }
            int rval = 0;
            for (auto& pi : mcnt[ki]) rval = max(rval, pi.second + dfs(dfs, tar^pi.first, ki+1));
            return memo[tar][ki] = rval;
        };
        int val1 = dfs(dfs), val2 = 0;
        vector<pair<int, int>> vlst(k, { -1, -1 });
        for (int i=0; i<k; ++i) for (auto& pi : mcnt[i]) vlst[i] = max(vlst[i], { pi.second, pi.first });
        sort(vlst.rbegin(), vlst.rend());
        for (int i=0; i<k-1; ++i) val2 += vlst[i].first;
        return n - max(val1, val2);
    }
};
