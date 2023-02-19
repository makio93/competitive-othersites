// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1.5e9);
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size(), res = INF;
        sort(nums.begin(), nums.end());
        for (int i=0; i+n-3<n; ++i) res = min(res, nums[i+n-3]-nums[i]);
        return res;
    }
};
