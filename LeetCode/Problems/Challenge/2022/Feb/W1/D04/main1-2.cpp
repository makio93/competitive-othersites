#include <bits/stdc++.h>
using namespace std;

// 解説AC,ハッシュマップ使用,空間計算量削減

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, res = 0;
        unordered_map<int, int> vcnt;
        vcnt[0] = -1;
        for (int i=0; i<n; ++i) {
            sum += nums[i] * 2 - 1;
            if (vcnt.find(sum) != vcnt.end()) res = max(res, i-vcnt[sum]);
            else vcnt[sum] = i;
        }
        return res;
    }
};
