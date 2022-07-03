// 解説AC4

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return n;
        int res = 1, dif = nums[1] - nums[0];
        if (dif != 0) ++res;
        for (int i=2; i<n; ++i) {
            int td = nums[i] - nums[i-1];
            if ((td>0&&dif<=0) || (td<0&&dif>=0)) {
                ++res;
                dif = td;
            }
        }
        return res;
    }
};
