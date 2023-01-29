// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> slst(n, vector<int>(n+1));
        vector<int> lcnt(n), rcnt(n);
        for (int i=0; i<n; ++i) lcnt[nums[i]-1]++;
        ll res = 0;
        for (int i=n-1; i>=1; --i) {
            lcnt[nums[i]-1]--;
            rcnt[nums[i]-1]++;
            for (int j=0; j<n; ++j) slst[nums[i]-1][j] = rcnt[j];
            for (int j=n-1; j>=0; --j) slst[nums[i]-1][j] += slst[nums[i]-1][j+1];
            int lsum = 0;
            for (int j=0; j<nums[i-1]-1; ++j) {
                lsum += lcnt[j];
                if (lcnt[j] == 0) res += (ll)lsum * slst[j][nums[i-1]];
            }
        }
        return res;
    }
};
