// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(), id = 0;
        vector<int> res(n);
        for (int i=0; i<n; ++i) if (nums[i]%2 == 0) {
            res[id] = nums[i];
            ++id;
        }
        for (int i=0; i<n; ++i) if (nums[i]%2 == 1) {
            res[id] = nums[i];
            ++id;
        }
        return res;
    }
};
