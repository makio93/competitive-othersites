// 本番1,TLE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), slen = nums.front().length();
        vector<int> ans(m);
        for (int i=0; i<m; ++i) {
            vector<int> ord(n);
            iota(ord.begin(), ord.end(), 0);
            sort(ord.begin(), ord.end(), [&](int li, int ri) -> bool {
                return (nums[li].substr(slen-queries[i][1]) != nums[ri].substr(slen-queries[i][1])) ? 
                    (nums[li].substr(slen-queries[i][1]) < nums[ri].substr(slen-queries[i][1])) : (li < ri);
            });
            ans[i] = ord[queries[i][0]-1];
        }
        return ans;
    }
};
