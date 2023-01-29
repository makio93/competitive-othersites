// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (n <= 2) return 0;
        vector<ll> vlst(n-1);
        for (int i=0; i<n-1; ++i) vlst[i] = (ll)weights[i] + weights[i+1];
        sort(vlst.begin(), vlst.end());
        ll lval = accumulate(vlst.begin(), vlst.begin()+k-1, 0LL), hval = accumulate(vlst.end()-(k-1), vlst.end(), 0LL);
        return hval - lval;
    }
};
