#include <bits/stdc++.h>
using namespace std;

// 自力AC1,Timeあまり良くない

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), res = 0;
        set<int> vals;
        for (int i=0; i<n; ++i) {
            vals.insert(nums[i]);
            int val = 0;
            for (int j=30; j>=0; --j) {
                int btar = 1 - ((nums[i]>>j)&1), li = val + (1<<j) * btar;
                auto titr = vals.lower_bound(li);
                if (titr!=vals.end() && *titr<li+(1LL<<j)) val += (1<<j) * btar;
                else val += (1<<j) * (1-btar);
            }
            res = max(res, nums[i]^val);
        }
        return res;
    }
};
