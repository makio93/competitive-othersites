#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        ll mval = nums[0];
        for (int t=0; t<2; ++t) {
            mval = max(mval, (ll)nums[0]);
            int r = 1, c = (nums[0] < 0) ? -1 : 1;
            ll nval = abs(nums[0]);
            for (int l=0; l<n; ++l) {
                if (nums[l] == 0) {
                    mval = max(mval, 0LL);
                    nval = (int)(1e9);
                    continue;
                }
                if (nval == (int)(1e9)) {
                    nval = abs(nums[l]);
                    c = (nums[l] < 0) ? -1 : 1;
                    mval = max(mval, nval*c);
                    r = l+1;
                }
                while (r<n && nums[r]!=0 && nval*abs(nums[r])>=nval) {
                    nval *= abs(nums[r]);
                    if (nums[r] < 0) c *= -1;
                    mval = max(mval, nval*c);
                    ++r;
                }
                if (nums[l] < 0) c *= -1;
                nval /= abs(nums[l]);
            }
            reverse(nums.begin(), nums.end());
        }
        return (int)(mval);
    }
};
