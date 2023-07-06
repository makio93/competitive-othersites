// 自力AC1(O(n)解)

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), res = INF, ri = 0, sum = 0;
        for (int li=0; li<n; ++li) {
            while (ri<n && sum<target) {
                sum += nums[ri];
                ++ri;
            }
            if (sum >= target) res = min(res, ri-li);
            sum -= nums[li];
        }
        return res == INF ? 0 : res;
    }
};
