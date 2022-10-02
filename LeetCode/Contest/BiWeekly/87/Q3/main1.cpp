// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> rids(30, -1), res(n, 1);
        for (int i=n-1; i>=0; --i) for (int j=0; j<30; ++j) {
            if (nums[i]&(1<<j)) rids[j] = i;
            res[i] = max(res[i], max(0, rids[j]-i+1));
        }
        return res;
    }
};
