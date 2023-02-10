// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> udp(n), ddp(n);
        udp[0] = ddp[0] = 1;
        for (int i=1; i<n; ++i) {
            udp[i] = udp[i-1];
            ddp[i] = ddp[i-1];
            if (nums[i] > nums[i-1]) udp[i] = max(udp[i], ddp[i-1]+1);
            if (nums[i] < nums[i-1]) ddp[i] = max(ddp[i], udp[i-1]+1);
        }
        return max(udp.back(), ddp.back());
    }
};
