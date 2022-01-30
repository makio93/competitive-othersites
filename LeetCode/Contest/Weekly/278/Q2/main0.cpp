#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum0(n+1), sum1(n+1);
        for (int i=0; i<n; ++i) {
            sum0[i+1] = sum0[i] + (nums[i]==0 ? 1 : 0);
            sum1[i+1] = sum1[i] + (nums[i]==1 ? 1 : 0);
        }
        vector<vector<int>> mcnt(n+1);
        for (int i=0; i<=n; ++i) mcnt[sum0[i]+(sum1[n]-sum1[i])].push_back(i);
        vector<int> res;
        for (int i=n; i>=0; --i) if (!mcnt[i].empty()) {
            res = mcnt[i];
            break;
        }
        return res;
    }
};
