#include <bits/stdc++.h>
using namespace std;

// 解説AC2

using ll = long long;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<ll, int>> cnt(n);
        int res = 0;
        for (int i=1; i<n; ++i) for (int j=0; j<i; ++j) {
            ll sub = (ll)nums[i] - nums[j];
            if (cnt[j].find(sub) != cnt[j].end()) {
                res += cnt[j][sub];
                cnt[i][sub] += cnt[j][sub] + 1;
            }
            else cnt[i][sub]++;
        }
        return res;
    }
};
