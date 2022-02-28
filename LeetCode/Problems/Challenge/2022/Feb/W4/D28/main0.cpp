// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> res;
        int li = 0;
        for (int i=0; i<n; ++i) {
            if (i+1>=n || (long long)nums[i+1]-nums[i]>1) {
                string val = to_string(nums[li]);
                if (li != i) val += string("->") + to_string(nums[i]);
                res.push_back(val);
                li = i+1;
            }
        }
        return res;
    }
};
