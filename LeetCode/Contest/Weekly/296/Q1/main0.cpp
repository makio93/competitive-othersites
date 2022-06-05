// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            int tn = n / 2;
            for (int i=0; i<tn; ++i) {
                if (i%2 == 0) nums[i] = min(nums[2*i], nums[2*i+1]);
                else nums[i] = max(nums[2*i], nums[2*i+1]);
            }
            n = tn;
        }
        return nums[0];
    }
};
