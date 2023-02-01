#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        vector<long long> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] = sums[i] + beans[i];
        long long res = sums[n];
        for (int i=0; i<n; ++i) res = min(res, sums[i]+sums[n]-sums[i+1]-(long long)beans[i]*(n-i-1));
        return res;
    }
};
