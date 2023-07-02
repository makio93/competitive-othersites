// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i=0; i<n; ++i) {
            multiset<int> mst;
            mst.insert(nums[i]);
            int val = 0;
            for (int j=i+1; j<n; ++j) {
                auto itr = mst.lower_bound(nums[j]);
                if (itr!=mst.begin() && itr!=mst.end() && *itr-*prev(itr)>1) --val;
                if (itr!=mst.begin() && nums[j]-*prev(itr)>1) ++val;
                if (itr!=mst.end() && *itr-nums[j]>1) ++val;
                mst.insert(nums[j]);
                res += val;
            }
        }
        return res;
    }
};
