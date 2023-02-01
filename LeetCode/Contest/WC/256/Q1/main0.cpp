#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
    const int INF = (int)(1e9);
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());
        int res = INF;
        for (int i=0; i+k-1<n; ++i) res = min(res, nums[i]-nums[i+k-1]);
        return res;
    }
};
