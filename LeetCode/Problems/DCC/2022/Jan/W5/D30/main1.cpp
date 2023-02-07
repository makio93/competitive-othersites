#include <bits/stdc++.h>
using namespace std;

// 解説AC,解法1

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        auto tmps = nums;
        for (int i=0; i<n; ++i) nums[(i+k)%n] = tmps[i];
    }
};
