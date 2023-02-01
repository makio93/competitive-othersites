// 本番TLE

#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
    int n;
    vector<int> tnums;
    map<pair<pair<int,int>,pair<vector<bool>,int>>, long long> memo;
    long long calc(vector<bool>& used, int i1, int i2, int d) {
        if (memo.find({{i1,i2},{used,d}}) != memo.end()) return memo[{{i1,i2},{used,d}}];
        long long val = gcd(tnums[i1], tnums[i2]) * d;
        if (d == n/2) return (memo[{{i1,i2},{used,d}}] = val);
        used[i1] = used[i2] = true;
        long long mval = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) if ((!used[i]) && (!used[j])) {
            mval = max(mval, calc(used, i, j, d+1));
        }
        used[i1] = used[i2] = false;
        return (memo[{{i1,i2},{used,d}}] = (mval + val));
    }
public:
    int maxScore(vector<int>& nums) {
        n = nums.size();
        vector<bool> used(n);
        tnums = nums;
        long long res = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) res = max(res, calc(used, i, j, 1));
        return (int)res;
    }
};
