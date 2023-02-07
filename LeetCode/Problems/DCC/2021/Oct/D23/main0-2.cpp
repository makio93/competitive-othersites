#include <bits/stdc++.h>
using namespace std;

// 自力AC2,平均計算量:O(NlogN)解,題意に適切な計算量

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] < nums[n-1]) return nums[0];
        int l = 0, r = n-1;
        while (r-l > 1) {
            set<int> ids({l, r});
            int cid = -1;
            while (cid==-1 && (int)(ids.size())<(r-l+1)) {
                set<int> cids;
                for (auto itr=ids.begin(); itr!=prev(ids.end()); ++itr) {
                    if (*next(itr)-*itr <= 1) continue;
                    int c = *itr + (*next(itr)-*itr) / 2;
                    if (nums[c]!=nums[l] || nums[c]!=nums[r]) {
                        cid = c;
                        break;
                    }
                    cids.insert(c);
                } 
                if (cid == -1) {
                    for (int ci : cids) ids.insert(ci);
                }
            }
            if (cid == -1) return nums[r];
            if (nums[cid] >= max(nums[l], nums[r])) l = cid;
            else r = cid;
        }
        return nums[r];
    }
};
