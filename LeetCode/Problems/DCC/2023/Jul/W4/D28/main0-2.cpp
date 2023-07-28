// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        function<int(int, int)> dp = [&](int li, int ri) {
            if (li == ri) {
                if ((n-1)%2 == 0) return nums[li];
                else return -nums[li];
            }
            else {
                if ((n-(ri-li+1))%2 == 0) return max(nums[li] + dp(li+1, ri), nums[ri] + dp(li, ri-1));
                else return min(-nums[li] + dp(li+1, ri), -nums[ri] + dp(li, ri-1));
            }
        };
        return dp(0, n-1) >= 0;
    }
};
