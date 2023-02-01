// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll countExcellentPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        vector<int> bcnt(61);
        for (int i=0; i<n; ++i) {
            int val = __builtin_popcount(nums[0]|nums[i]) + __builtin_popcount(nums[0]&nums[i]);
            bcnt[val]++;
        }
        for (int i=0; i<60; ++i) bcnt[i+1] += bcnt[i];
        ll res = n - bcnt[k-1];
        for (int i=1; i<n; ++i) {
            int sub = __builtin_popcount(nums[i]) - __builtin_popcount(nums[i-1]);
            k -= sub;
            res += n - bcnt[max(0, min(k-1, 60))];
        }
        return res;
    }
};
