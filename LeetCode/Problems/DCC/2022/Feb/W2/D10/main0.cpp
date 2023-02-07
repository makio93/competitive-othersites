#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<int> sums(n+1);
        for (int i=0; i<n; ++i) sums[i+1] += sums[i] + nums[i];
        unordered_map<int, int> scnt;
        for (int i=0; i<=n; ++i) {
            if (scnt.find(sums[i]-k) != scnt.end()) res += scnt[sums[i]-k];
            scnt[sums[i]]++;
        }
        return res;
    }
};
