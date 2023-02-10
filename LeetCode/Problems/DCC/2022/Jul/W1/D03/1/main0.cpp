// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> udp(n, 1), ddp(n, 1);
        for (int i=1; i<n; ++i) for (int j=0; j<i; ++j) {
            if (nums[j] < nums[i]) udp[i] = max(udp[i], ddp[j]+1);
            if (nums[j] > nums[i]) ddp[i] = max(ddp[i], udp[j]+1);
        }
        int res = max(*max_element(udp.begin(), udp.end()), *max_element(ddp.begin(), ddp.end()));
        return res;
    }
};
