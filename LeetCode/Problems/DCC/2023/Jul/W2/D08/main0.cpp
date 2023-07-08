// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> vlst;
        for (int i=0; i<n-1; ++i) vlst.push_back(weights[i]+weights[i+1]);
        sort(vlst.begin(), vlst.end());
        ll hval = accumulate(vlst.end()-(k-1), vlst.end(), 0LL), lval = accumulate(vlst.begin(), vlst.begin()+(k-1), 0LL);
        return hval - lval;
    }
};
