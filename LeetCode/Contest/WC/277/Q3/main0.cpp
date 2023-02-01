#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i=0; i<n; ++i) {
            bool ok = true;
            if (i-1>=0 && nums[i]-nums[i-1]<=1) ok = false;
            if (i+1<n && nums[i+1]-nums[i]<=1) ok = false;
            if (ok) res.push_back(nums[i]);
        }
        return res;
    }
};
