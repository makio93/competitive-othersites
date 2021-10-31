#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; ++i) if (nums[i] == i%10) return i;
        return -1;
    }
};
