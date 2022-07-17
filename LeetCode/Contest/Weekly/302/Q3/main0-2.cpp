// 本番2,AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), slen = nums.front().length();
        vector<vector<int>> ords(slen);
        vector<int> td(n);
        iota(td.begin(), td.end(), 0);
        for (int i=slen-1; i>=0; --i) {
            vector<vector<int>> tids(10);
            for (int j=0; j<n; ++j) tids[nums[td[j]][i]-'0'].push_back(td[j]);
            for (int j=0; j<10; ++j) for (int vid : tids[j]) ords[slen-i-1].push_back(vid);
            td = ords[slen-i-1];
        }
        vector<int> ans(m);
        for (int i=0; i<m; ++i) ans[i] = ords[queries[i][1]-1][queries[i][0]-1];
        return ans;
    }
};
