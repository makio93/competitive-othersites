// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
    vector<int> plst;
    bool is_squarefree(int val) {
        for (int i=2; i*i<=val; ++i) if (val%(i*i) == 0) return false;
        return true;
    }
    int make_mask(int val) {
        int mask = 0;
        for (int i=0; i<(int)(plst.size()); ++i) if (val%plst[i] == 0) mask |= 1<<i;
        return mask;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        int n = nums.size(), mval = *max_element(nums.begin(), nums.end());
        vector<bool> is_prime(mval+1, true);
        for (int i=2; i<=mval; ++i) if (is_prime[i]) {
            for (int j=i*2; j<=mval; j+=i) is_prime[j] = false;
        }
        for (int i=2; i<=mval; ++i) if (is_prime[i]) plst.push_back(i);
        unordered_map<int, ll> dp, ndp;
        dp[0] = 1;
        for (int i=0; i<n; ++i) {
            ndp = dp;
            if (is_squarefree(nums[i])) {
                int mask = make_mask(nums[i]);
                for (const auto& pi : dp) if ((pi.first&mask) == 0) {
                    int nmask = pi.first | mask;
                    ndp[nmask] = (ndp[nmask] + pi.second) % mod;
                }
            }
            swap(ndp, dp);
        }
        ll res = 0;
        for (const auto& pi : dp) res = (res + pi.second) % mod;
        res = (res - 1 + mod) % mod;
        return (int)res;
    }
};
