// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<ll> dp(n, 1);
        unordered_map<int, int> aids;
        for (int i=0; i<n; ++i) aids[arr[i]] = i;
        for (int i=0; i<n; ++i) for (int j=0; j<i; ++j) 
            if (arr[i]%arr[j]==0 && aids.find(arr[i]/arr[j])!=aids.end()) 
                dp[i] = (dp[i] + dp[j] * dp[aids[arr[i]/arr[j]]]) % mod;
        ll res = 0;
        for (int i=0; i<n; ++i) res = (res + dp[i]) % mod;
        return (int)res;
    }
};
