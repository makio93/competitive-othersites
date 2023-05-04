// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bids(30, -1), res(n);
        for (int i=n-1; i>=0; --i) {
            for (int j=0; j<30; ++j) if (nums[i]&(1<<j)) bids[j] = i;
            res[i] = max(1, *max_element(bids.begin(), bids.end()) - i + 1);
        }
        return res;
    }
};
