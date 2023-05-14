// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high+1, -1);
        auto dfs = [&](auto& dfs, int end) -> int {
            if (memo[end] != -1) return memo[end];
            if (end == 0) return memo[end] = 1;
            int val = 0;
            if (end-zero >= 0) val = (val + dfs(dfs, end-zero)) % mod;
            if (end-one >= 0) val = (val + dfs(dfs, end-one)) % mod;
            return memo[end] = val;
        };
        int res = 0;
        for (int i=low; i<=high; ++i) res = (res + dfs(dfs, i)) % mod;
        return res;
    }
};
