// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] += sums[i] + nums[i];
        vector<int> res(n, -1);
        for (int i=0; i<n; ++i) {
            if (i-k < 0 || i+k >= n) continue;
            res[i] = (sums[i+1+k] - sums[i-k]) / (2*k + 1);
        }
        return res;
    }
};
