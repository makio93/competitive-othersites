// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> plst;
        for (int i=2; i<=30; ++i) {
            bool ok = true;
            for (int j=2; j<i; ++j) if (i%j == 0) ok = false;
            if (ok) plst.push_back(i);
        }
        int plen = plst.size();
        vector<int> blst(31);
        for (int i=1; i<=30; ++i) {
            for (int j=0; j<plen; ++j) {
                if (i%(plst[j]*plst[j]) == 0) {
                    blst[i] = -1;
                    break;
                }
                if (i%plst[j] == 0) blst[i] |= 1<<j;
            }
        }
        vector<int> vcnt(31);
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        vector<ll> dp(1<<plen);
        ll one = 1;
        for (int i=0; i<vcnt[1]; ++i) one = one * 2 % mod;
        dp[(1<<plen)-1] = one;
        for (int i=2; i<=30; ++i) {
            if (blst[i]==-1 || vcnt[i]==0) continue;
            for (int j=0; j<1<<plen; ++j) if ((j|blst[i]) == j) dp[j^blst[i]] = (dp[j^blst[i]] + dp[j] * vcnt[i] % mod) % mod;
        }
        ll res = 0;
        for (int i=0; i<(1<<plen)-1; ++i) res = (res + dp[i]) % mod;
        return (int)res;
    }
};
