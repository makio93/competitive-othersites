#include <bits/stdc++.h>
using namespace std;

// 自力解答2,AC

class Solution {
    const int INF = (int)(1e9);
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> rmin(n+1, INF);
        for (int i=n; i>0; --i) rmin[i-1] = min(rmin[i], nums[i-1]);
        int lmax = 0, res = n;
        for (int i=0; i<n; ++i) {
            lmax = max(lmax, nums[i]);
            if (lmax <= rmin[i+1]) {
                res = min(res, i+1);
                break;
            }
        }
        return res;
    }
};
