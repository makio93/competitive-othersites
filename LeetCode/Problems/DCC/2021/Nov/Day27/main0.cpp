#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), zcnt = count(nums.begin(), nums.end(), 0);
        vector<int> res(n);
        if (zcnt == 1) {
            int mul = 1;
            for (int i=0; i<n; ++i) if (nums[i] != 0) mul *= nums[i];
            res[distance(nums.begin(), find(nums.begin(), nums.end(), 0))] = mul;
        }
        else if (zcnt == 0) {
            vector<ll> sub(n);
            ll nval = 1;
            for (int i=0; i<n; ++i) {
                sub[i] = nval;
                nval *= nums[i];
            }
            nval = 1;
            for (int i=n-1; i>=0; --i) {
                res[i] = sub[i] * nval;
                nval *= nums[i];
            }
        }
        return res;
    }
};
