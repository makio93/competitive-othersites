// 本番,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        vector<ll> sums(n+1), sum1(n+1);
        for (int i=0; i<n; ++i) sum1[i+1] = (sum1[i] + strength[i]) % mod;
        for (int i=0; i<n; ++i) sums[i+1] = (sum1[i+1] + sums[i]) % mod;
        stack<pair<int, int>> st;
        stack<ll> sst;
        ll res = 0;
        for (int i=0; i<n; ++i) {
            // ll sub = 0;
            while (!st.empty() && st.top().first>=strength[i]) {
                //sub = (sub + sst.top()) % mod;
                sst.pop();
                st.pop();
            }
            int sval = 0;
            if (!st.empty()) sval = st.top().second;
            ll add = 0;
            if (!st.empty()) add = sst.top();
            add = (add + (sums[i+1]-sums[sval]) * strength[i]) % mod;
            res = (res + (add+mod)) % mod;
            sst.push(add%mod);
            st.emplace(strength[i], i+1);
        }
        return (int)res;
    }
};
