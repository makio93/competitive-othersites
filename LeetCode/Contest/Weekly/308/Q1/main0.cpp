// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] = sums[i] + nums[i];
        vector<int> res(m);
        for (int i=0; i<m; ++i) res[i] = upper_bound(sums.begin(), sums.end(), queries[i]) - sums.begin() - 1;
        return res;
    }
};
