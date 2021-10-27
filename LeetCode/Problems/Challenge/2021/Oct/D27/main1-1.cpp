#include <bits/stdc++.h>
using namespace std;

// 解説AC1,Time:O(n),Space:O(1)解法

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lid = 0, rid = n-1;
        for (int i=0; i<n; ++i) {
            while (i<rid && nums[i]==2) { swap(nums[rid], nums[i]); --rid; }
            while (i>lid && nums[i]==0) { swap(nums[lid], nums[i]); ++lid; }
        }
    }
};
