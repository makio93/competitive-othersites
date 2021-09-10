#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long long, int>> cnts(n), subs(n);
        for (int i=1; i<n; ++i) for (int j=0; j<i; ++j) {
            if (cnts[j].find((long long)nums[i]-nums[j]) != cnts[j].end()) cnts[i][(long long)nums[i]-nums[j]] += cnts[j][(long long)nums[i]-nums[j]];
            if (subs[j].find((long long)nums[i]-nums[j]) != subs[j].end()) cnts[i][(long long)nums[i]-nums[j]] += subs[j][(long long)nums[i]-nums[j]];
            subs[i][(long long)nums[i]-nums[j]]++;
        }
        int res = 0;
        for (int i=1; i<n; ++i) for (auto p : cnts[i]) res += p.second;
        return res;
    }
};
