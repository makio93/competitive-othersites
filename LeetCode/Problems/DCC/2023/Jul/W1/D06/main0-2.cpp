// 自力AC2(O(nlog n)解)

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), res = INF;
        vector<int> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] += sums[i] + nums[i];
        for (int i=0; i<n; ++i) {
            int id = lower_bound(sums.begin(), sums.end(), sums[i]+target) - sums.begin();
            if (id <= n) res = min(res, id-i);
        }
        return res == INF ? 0 : res;
    }
};
