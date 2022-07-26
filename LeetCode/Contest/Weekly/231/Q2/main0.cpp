// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int n = nums.size();
        long long sum = 0;
        for (int i=0; i<n; ++i) sum += nums[i];
        long long sub = llabs(sum - goal);
        return (int)((sub+limit-1) / limit);
    }
};
