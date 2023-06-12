// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<string> res;
        if (n == 1) res.push_back(to_string(nums[0]));
        if (n <= 1) return res;
        int li = nums[0];
        for (int i=1; i<n; ++i) {
            if (nums[i-1] < nums[i]-1) {
                if (li == nums[i-1]) res.push_back(to_string(li));
                else res.push_back(to_string(li)+"->"+to_string(nums[i-1]));
                li = nums[i];
            }
            if (i == n-1) {
                if (li == nums[i]) res.push_back(to_string(li));
                else res.push_back(to_string(li)+"->"+to_string(nums[i]));
            }
        }
        return res;
    }
};
