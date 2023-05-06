// 解説AC2

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
        int li = 0, ri = n-1;
        while (ri-li >= 0) {
            if (nums[li]+nums[ri] <= target) {
                res = (res + twos[ri-li]) % mod;
                ++li;
            }
            else --ri;
        }
        return res;
    }
};
