// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1);
        for (int i=0; i<n; ++i) sum[i+1] += sum[i] + nums[i];
        int res = -1;
        for (int i=1; i<=n; ++i) if (sum[i-1] == sum[n]-sum[i]) {
            res = i-1;
            break;
        }
        return res;
    }
};
