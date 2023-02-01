// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> choose(n);
        int cnt = 1;
        for (int i=1; i<n; ++i) {
            if (cnt >= k) choose[i] = true;
            if (nums[i] <= nums[i-1]) ++cnt;
            else cnt = 1;
        }
        cnt = 1;
        vector<int> res;
        for (int i=n-2; i>=0; --i) {
            if (cnt>=k && choose[i]) res.push_back(i);
            if (nums[i+1] >= nums[i]) ++cnt;
            else cnt = 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
