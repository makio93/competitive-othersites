// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        multiset<int, greater<int>> lst;
        multiset<int> mst;
        vector<int> res(n-k+1);
        int li = 0, ri = 0;
        while (li+k-1 < n) {
            while (ri < li+k) {
                lst.insert(nums[ri]);
                ++ri;
            }
            while ((int)(lst.size()) > x) {
                mst.insert(*lst.begin());
                lst.erase(lst.begin());
            }
            res[li] = min(0, *lst.begin());
            if (lst.find(nums[li]) != lst.end()) lst.erase(lst.find(nums[li]));
            else mst.erase(mst.find(nums[li]));
            ++li;
            while (!mst.empty() && (int)(lst.size())<x) {
                lst.insert(*mst.begin());
                mst.erase(mst.begin());
            }
        }
        return res;
    }
};
