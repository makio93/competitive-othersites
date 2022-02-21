// 自力AC2-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ncnt = 1;
        for (int i=1; i<(int)(nums.size()); ++i) {
            if (nums[i-1] == nums[i]) ++ncnt;
            else ncnt = 1;
            if (ncnt > nums.size()/2) return nums[i];
        }
        return nums.front();
    }
};
