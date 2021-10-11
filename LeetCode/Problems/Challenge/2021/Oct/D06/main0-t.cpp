#include <bits/stdc++.h>
using namespace std;

// 自力実装,Space:O(1)でない解法

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> vcnt(n);
        for (int i=0; i<n; ++i) vcnt[nums[i]-1]++;
        vector<int> res;
        for (int i=0; i<n; ++i) if (vcnt[i] == 2) res.push_back(i+1);
        return res;
    }
};
