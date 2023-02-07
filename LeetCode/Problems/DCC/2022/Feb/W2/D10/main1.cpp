#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> scnt;
        scnt[sum]++;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            if (scnt.find(sum-k) != scnt.end()) res += scnt[sum-k];
            scnt[sum]++;
        }
        return res;
    }
};
