// 解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)(1e9) + 7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        vector<int> twos(n+1);
        twos[0] = 1;
        for (int i=1; i<=n; ++i) twos[i] = twos[i-1] * 2 % mod;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i) {
            int ri = upper_bound(nums.begin(), nums.end(), target-nums[i]) - nums.begin() - 1;
            if (ri-i >= 0) res = (res + twos[ri-i]) % mod;
        }
        return res;
    }
};
