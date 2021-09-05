#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> vals(101);
        for (int i=2; i<n; ++i) vals[nums[i]]++;
        int res = 0;
        for (int c=2; c<n; ++c) {
            vals[nums[c]]--;
            for (int a=0; a<c; ++a) for (int b=a+1; b<c; ++b) if (nums[a]+nums[b]+nums[c] <= 100) res += vals[nums[a]+nums[b]+nums[c]];
        }
        return res;
    }
};
