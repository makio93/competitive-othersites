// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> plst;
        vector<bool> sieve(31);
        for (int i=2; i<=30; ++i) if (!sieve[i]) {
            plst.push_back(i);
            for (int j=i*i; j<=30; j+=i) sieve[j] = true;
        }
        int plen = plst.size();
        vector<int> blst;
        for (int i=0; i<n; ++i) {
            bool ok = true;
            for (int j=0; j<plen; ++j) if (nums[i]%(plst[j]*plst[j]) == 0) ok = false;
            if (!ok) continue;
            int bval = 0;
            for (int j=0; j<plen; ++j) if (nums[i]%plst[j] == 0) bval |= 1<<j;
            blst.push_back(bval);
        }
        int blen = blst.size();
        if (blen == 0) return 0;
        sort(blst.begin(), blst.end());
        vector<pair<int, int>> bcnt;
        bcnt.emplace_back(blst[0], 1);
        for (int i=1; i<blen; ++i) {
            if (bcnt.back().first == blst[i]) bcnt.back().second++;
            else bcnt.emplace_back(blst[i], 1);
        }
        int m = bcnt.size();
        vector<ll> dp(1<<plen, 0), ndp;
        int one = bcnt[0].first == 0 ? bcnt[0].second : 0;
        dp[0] = 1;
        while (one > 0) {
            dp[0] = dp[0] * 2 % mod;
            --one;
        }
        for (int i=0; i<m; ++i) if (bcnt[i].first != 0) {
            ndp = dp;
            for (int j=0; j<1<<plen; ++j) if (!(j&bcnt[i].first)) ndp[j|bcnt[i].first] = (ndp[j|bcnt[i].first] + dp[j]*bcnt[i].second%mod) % mod;
            swap(ndp, dp);
        }
        ll res = 0;
        for (int i=1; i<1<<plen; ++i) res = (res + dp[i]) % mod;
        return (int)res;
    }
};
