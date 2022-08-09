// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> ast;
        for (int i=0; i<n; ++i) ast.insert(arr[i]);
        unordered_map<int, int> memo;
        auto dfs = [&](auto dfs, int val) -> int {
            if (memo.find(val) != memo.end()) return memo[val];
            int rval = 1;
            for (int aval : ast) if (val%aval==0 && ast.find(val/aval)!=ast.end()) {
                rval = (int)((rval + ((ll)dfs(dfs, aval) * dfs(dfs, val/aval) % mod)) % mod);
            }
            return memo[val] = rval;
        };
        int res = 0;
        for (int val : ast) res = (res + dfs(dfs, val)) % mod;
        return res;
    }
};
