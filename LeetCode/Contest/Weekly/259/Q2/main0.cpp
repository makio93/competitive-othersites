#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    const int INF = (int)(1e9);
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> vals(n);
        for (int i=1; i<=n-2; ++i) if (nums[i-1]<nums[i] && nums[i]<nums[i+1]) vals[i] = 1;
        int lval = nums[0], rval = nums[n-1];
        vector<bool> twos(n, true);
        for (int i=1; i<=n-2; ++i) {
            if (nums[i] <= lval) twos[i] = false;
            lval = max(lval, nums[i]);
        }
        for (int i=n-2; i>=1; --i) {
            if (nums[i] >= rval) twos[i] = false;
            rval = min(rval, nums[i]);
        }
        for (int i=1; i<=n-2; ++i) if (twos[i]) vals[i] = max(vals[i], 2);
        int res = 0;
        for (int i=1; i<=n-2; ++i) res += vals[i];
        return res;
    }
};
