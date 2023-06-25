// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size(), li = -1;
        if (count(nums.begin(), nums.end(), 1) == 0) return 0;
        ll res = 1;
        for (int i=0; i<n; ++i) if (nums[i] == 1) {
            if (li != -1) res = res * (i - li) % mod;
            li = i;
        }
        return (int)res;
    }
};
