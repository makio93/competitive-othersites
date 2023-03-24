// 学習1回目,解説0,TLE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), li = n, ri = 0;
        for (int i=0; i<n-1; ++i) for (int j=i+1; j<n; ++j) if (nums[j] < nums[i]) {
            li = min(li, i);
            ri = max(ri, j);
        }
        return max(0, ri-li+1);
    }
};
