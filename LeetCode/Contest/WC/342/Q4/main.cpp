// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), scnt = count(nums.begin(), nums.end(), 1);
        if (scnt > 0) return n - scnt;
        int gval = gcd(nums[0], nums[1]);
        for (int i=2; i<n; ++i) gval = gcd(gval, nums[i]);
        if (gval > 1) return -1;
        int mval = n;
        for (int i=1; i<n; ++i) {
            for (int j=0; j+i<n; ++j) {
                int tval = nums[j];
                for (int j2=j+1; j2<=j+i; ++j2) tval = gcd(tval, nums[j2]);
                if (tval == 1) {
                    mval = i;
                    break;
                }
            }
            if (mval < n) break;
        }
        return mval + n - 1;
    }
};
