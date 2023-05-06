// 自力AC2

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
        for (int i=0,li=0; i<n; ++i) {
            if (nums[i]+nums[i] <= target) res = (res + 1) % mod;
            while (li-1>=0 && nums[i]+nums[li-1]>target) --li;
            res = (res + twos[i-li] * (ll)((twos[li] - 1 + mod) % mod)) % mod;
            while (i+1<n && li<i+1 && nums[i+1]+nums[li]<=target) ++li;
        }
        return res;
    }
};
