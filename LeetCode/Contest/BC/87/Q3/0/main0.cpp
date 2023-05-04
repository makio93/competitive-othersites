// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size(), mval = 0, rid = n-1;
        vector<int> bcnt(30), res(n);
        for (int i=n-1; i>=0; --i) {
            mval |= nums[i];
            for (int j=0; j<30; ++j) if ((nums[i])&(1<<j)) bcnt[j]++;
            while (rid > i) {
                bool single = false;
                for (int j=0; j<30; ++j) if (((nums[rid])&(1<<j)) && bcnt[j]==1) single = true;
                if (single) break;
                for (int j=0; j<30; ++j) if ((nums[rid])&(1<<j)) bcnt[j]--;
                --rid;
            }
            res[i] = rid - i + 1;
        }
        return res;
    }
};
