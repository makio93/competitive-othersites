#include <bits/stdc++.h>
using namespace std;

// 自力解答1,AC

class Solution {
    const int INF = (int)(1e9);
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmax(n+1), rmin(n+1, INF);
        for (int i=0; i<n; ++i) lmax[i+1] = max(lmax[i], nums[i]);
        for (int i=n; i>0; --i) rmin[i-1] = min(rmin[i], nums[i-1]);
        int res = n;
        for (int i=1; i<=n; ++i) if (lmax[i] <= rmin[i]) res = min(res, i);
        return res;
    }
};
