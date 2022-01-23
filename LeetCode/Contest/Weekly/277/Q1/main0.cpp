#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> vcnt;
        vcnt.emplace_back(nums[0], 1);
        for (int i=1; i<n; ++i) {
            if (nums[i] == vcnt.back().first) vcnt.back().second++;
            else vcnt.emplace_back(nums[i], 1);
        }
        int m = vcnt.size(), res = 0;
        for (int i=1; i<m-1; ++i) res += vcnt[i].second;
        return res;
    }
};
