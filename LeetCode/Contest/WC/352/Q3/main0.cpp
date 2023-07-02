// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(), li = 0;
        ll res = 0;
        multiset<int> mst;
        for (int ri=0; ri<n; ++ri) {
            mst.insert(nums[ri]);
            while (*mst.rbegin()-*mst.begin() > 2) {
                mst.erase(mst.find(nums[li]));
                ++li;
            }
            res += (ll)ri - li + 1;
        }
        return res;
    }
};
