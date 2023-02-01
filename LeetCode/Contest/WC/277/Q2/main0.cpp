#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), pid = 0, nid = 0;
        vector<int> res;
        for (int i=0; i<n; ++i) {
            if (i%2 == 0) {
                while (pid<n && nums[pid]<0) ++pid;
                res.push_back(nums[pid]);
                ++pid;
            }
            else {
                while (nid<n && nums[nid]>0) ++nid;
                res.push_back(nums[nid]);
                ++nid;
            }
        }
        return res;
    }
};
