// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = nums.front();
        for (int i=0; i<n; ++i) {
            ans = max(ans, sum);
            if (i+1<n) {
                if (nums[i+1]-nums[i]>0) sum += nums[i+1];
                else sum = nums[i+1];
            }
        }
        return ans;
    }
};
