#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] += sum[i] + nums[i];
        map<ll, unordered_set<int>> okval;
        vector<unordered_set<int>> pivots(n);
        unordered_set<int> pivots0;
        for (int i=1; i<n; ++i) {
            okval[(ll)k-nums[i-1]].insert(i-1);
            ll lval = sum[i], rval = sum[n] - sum[i];
            if (lval == rval) pivots0.insert(i);
            if (okval.find(rval-lval) != okval.end()) {
                for (auto sid : okval[rval-lval]) pivots[sid].insert(i);
            }
        }
        okval.clear();
        for (int i=n-1; i>=1; --i) {
            okval[(ll)k-nums[i]].insert(i);
            ll lval = sum[i], rval = sum[n] - sum[i];
            if (lval == rval) pivots0.insert(i);
            if (okval.find(lval-rval) != okval.end()) {
                for (auto sid : okval[lval-rval]) pivots[sid].insert(i);
            }
        }
        int res = (int)(pivots0.size());
        for (int i=0; i<n; ++i) res = max(res, (int)(pivots[i].size()));
        return res;
    }
};
