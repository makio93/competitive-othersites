#include <bits/stdc++.h>
using namespace std;

// 自力AC

const int INF = (int)(1e9);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] = sum[i] + nums[i];
        int res = -INF, mval = 0;
        for (int i=1; i<=n; ++i) {
            res = max(res, sum[i]-mval);
            mval = min(mval, sum[i]);
        }
        return res;
    }
};
