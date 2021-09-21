#include <bits/stdc++.h>
using namespace std;

// 自力AC1

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> run;
        run.emplace_back(nums.front(), 1);
        for (int i=1; i<n; ++i) {
            if (nums[i] == run.back().first) run.back().second++;
            else run.emplace_back(nums[i], 1);
        }
        int res = 0;
        for (auto p : run) if (p.first == 1) res = max(res, p.second);
        return res;
    }
};
