#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res = nums;
        for (int i=0; i<n-1; ++i) res[i+1] += res[i];
        return res;
    }
};
