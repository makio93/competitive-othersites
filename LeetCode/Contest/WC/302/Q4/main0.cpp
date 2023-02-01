// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = (int)(1e9);
    int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size(), m = numsDivide.size();
        int gval = numsDivide[0];
        for (int i=1; i<m; ++i) gval = gcd(gval, numsDivide[i]);
        int mval = INF;
        sort(nums.begin(), nums.end());
        for (int i=1; i*i<=gval; ++i) if (gval%i == 0) {
            int ai = i, bi = gval / i;
            int lid = lower_bound(nums.begin(), nums.end(), ai) - nums.begin();
            if (lid<n && nums[lid]==ai) mval = min(mval, lid);
            if (ai == bi) continue;
            lid = lower_bound(nums.begin(), nums.end(), bi) - nums.begin();
            if (lid<n && nums[lid]==bi) mval = min(mval, lid);
        }
        return (mval == INF) ? -1 : mval;
    }
};
