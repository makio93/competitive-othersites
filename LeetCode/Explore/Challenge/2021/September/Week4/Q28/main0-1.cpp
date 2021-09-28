#include <bits/stdc++.h>
using namespace std;

// 自力AC,Space:O(N)

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), pid = { 0, 1 };
        for (int i=0; i<n; ++i) {
            res[pid[nums[i]%2]] = nums[i];
            pid[nums[i]%2] += 2;
        }
        return res;
    }
};
