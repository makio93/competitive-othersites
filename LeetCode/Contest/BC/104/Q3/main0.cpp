// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bcnt(30);
        for (int i=0; i<n; ++i) for (int j=0; j<30; ++j) if (nums[i]&(1<<j)) bcnt[j]++;
        ll res = 0;
        for (int i=0; i<n; ++i) {
            ll val = 0;
            for (int j=0; j<30; ++j) {
                if (nums[i]&(1<<j)) {
                    val |= 1LL<<(j+k);
                    if (bcnt[j]-1 > 0) val |= 1LL<<j;
                }
                else {
                    if (bcnt[j] > 0) val |= 1LL<<j;
                }
            }
            res = max(res, val);
        }
        return res;
    }
};
