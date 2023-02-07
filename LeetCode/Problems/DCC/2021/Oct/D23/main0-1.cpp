#include <bits/stdc++.h>
using namespace std;

// 自力AC1,O(N)解,題意に不適切な計算量

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        for (int i=1; i<n; ++i) res = min(res, nums[i]);
        return res; 
    }
};
