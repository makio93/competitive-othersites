#include <bits/stdc++.h>
using namespace std;

// 本番参加2,TLE

using ll = long long;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), h = n / 2;
        for (int i=0; i<n; ++i) nums[i] += (int)(1e7);
        ll res = (ll)(1e15), val1 = 0, val2 = 0;
        map<pair<int, int>, ll> memo, pmemo;
        function<void(int,int)> dfs = [&](int d, int ci) {
            bool ok = true;
            if (val1-val2 >= 0) {
                if (memo.find({d, ci}) == memo.end()) ok = false;
                else {
                    if (memo[{d, ci}] > val1-val2) {
                        memo[{d, ci}] = val1 - val2;
                        ok = false;
                    }
                }
            }
            else {
                if (pmemo.find({d, ci}) == pmemo.end()) ok = false;
                else {
                    if (pmemo[{d, ci}] > -(val1-val2)) {
                        pmemo[{d, ci}] = -(val1-val2);
                        ok = false;
                    }
                }
            }
            if (ok) return;
            if (d == n) res = min(res, abs(val1-val2));
            else {
                if (ci < h) {
                    val1 += nums[d];
                    dfs(d+1, ci+1);
                    val1 -= nums[d];
                }
                if (d-ci < h) {
                    val2 += nums[d];
                    dfs(d+1, ci);
                    val2 -= nums[d];
                }
            }
        };
        dfs(0, 0);
        return (int)res;
    }
};
