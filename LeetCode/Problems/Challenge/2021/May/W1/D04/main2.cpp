#include <bits/stdc++.h>
using namespace std;

// 解説AC,データ書き換えなし

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool modified = false;
        for (int i=0; i+1<n; ++i) {
            if (nums[i+1] < nums[i]) {
                if (modified) return false;
                modified = true;
                if (i-1>=0 && nums[i-1]>nums[i+1] && i+2<n && nums[i+2]<nums[i]) return false;
            }
        }
        return true;
    }
};
