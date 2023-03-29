// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

const static long long MAX = numeric_limits<int>::max();
class Solution {
    vector<int> memo;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (memo.empty()) memo.assign(target+1, -1);
        if (memo[target] != -1) return memo[target];
        if (target == 0) return memo[target] = 1;
        long long val = 0;
        for (const int& num : nums) if (target-num >= 0) {
            val += combinationSum4(nums, target-num);
            if (val > MAX) return (int)MAX;
        }
        return memo[target] = (int)val;
    }
};
