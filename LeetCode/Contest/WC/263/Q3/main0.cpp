#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        map<int, int> bcnt;
        for (int i=0; i<(1<<n); ++i) {
            int xval = 0;
            for (int j=0; j<n; ++j) if ((i>>j) & 1) xval |= nums[j];
            bcnt[xval]++;
        }
        return bcnt.rbegin()->second;
    }
};
