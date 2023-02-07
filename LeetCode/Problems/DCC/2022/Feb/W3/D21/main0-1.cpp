// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        for (auto pi : vcnt) if (pi.second > n/2) return pi.first;
        return nums.front();
    }
};
