// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for (int i=0; i+1<n; ++i) if (nums[i+1] < nums[i]) {
            if (cnt > 0) return false;
            if (i+2>=n || nums[i+2]>=nums[i]) {
                nums[i+1] = nums[i];
                ++cnt;
            }
            else if (i-1<0 || nums[i+1]>=nums[i-1]) {
                nums[i] = nums[i+1];
                ++cnt;
            }
            else return false;
        }
        return true;
    }
};
