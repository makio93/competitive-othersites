// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vlst;
        vlst.emplace_back(nums[0], 1);
        for (int i=1; i<n; ++i) {
            if (nums[i] == vlst.back().first) vlst.back().second++;
            else vlst.emplace_back(nums[i], 1);
        }
        ll res = 0;
        for (auto pi : vlst) if (pi.first == 0) res += (ll)pi.second * (pi.second+1) / 2;
        return res;
    }
};
