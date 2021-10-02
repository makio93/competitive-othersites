#include <bits/stdc++.h>
using namespace std;

// 本番WA

using ll = long long;
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> vals;
        for (int i=0; i<n; ++i) vals[nums[i]].push_back(i);
        vector<bool> change(n);
        for (auto pi : vals) {
            int len = pi.second.size();
            change[pi.second[(len-1)/2]] = true;
            for (int i2=-1; i2<=2; ++i2) if ((len-1)/2+i2>=0 && (len-1)/2+i2<len) change[pi.second[(len-1)/2+i2]] = true;
            change[pi.second.front()] = change[pi.second.back()] = true;
            for (int i=2; i<(len-1)/2; i+=3) change[pi.second[i]] = true;
            for (int i=len-3; i>=(len-1)/2+1; i-=3) change[pi.second[i]] = true;
        }
        vector<ll> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] += sum[i] + nums[i];
        map<ll, vector<int>> lokval, rokval;
        vector<unordered_set<int>> pivots(n);
        unordered_set<int> pivots0;
        for (int i=1; i<n; ++i) {
            if (change[i-1]) lokval[(ll)k-nums[i-1]].push_back(i-1);
            ll lval = sum[i], rval = sum[n] - sum[i];
            if (lval == rval) pivots0.insert(i);
            if (lokval.find(rval-lval) != lokval.end()) for (auto vid : lokval[rval-lval]) pivots[vid].insert(i);
        }
        for (int i=n-1; i>=1; --i) {
            if (change[i]) rokval[(ll)k-nums[i]].push_back(i);
            ll lval = sum[i], rval = sum[n] - sum[i];
            if (lval == rval) pivots0.insert(i);
            if (rokval.find(lval-rval) != rokval.end()) for (auto vid : rokval[lval-rval]) pivots[vid].insert(i);
        }
        /*
        for (auto pi : lokval) if (rokval.find(pi.first) != rokval.end()) {
            int li = pi.second, ri = rokval[pi.first];
            pivots[li].insert(pivots[ri].begin(), pivots[ri].end());
        }
        */
        int res = (int)(pivots0.size());
        for (int i=0; i<n; ++i) res = max(res, (int)(pivots[i].size()));
        return res;
    }
};
