// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> rsum(n+1);
        for (int i=n-1; i>=0; --i) rsum[i] = rsum[i+1] + nums[i];
        ll lsum = 0;
        int res = 0;
        for (int i=0; i<n-1; ++i) {
            lsum += nums[i];
            if (lsum >= rsum[i+1]) ++res;
        }
        return res;
    }
};
