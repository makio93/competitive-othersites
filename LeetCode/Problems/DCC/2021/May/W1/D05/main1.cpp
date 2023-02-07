#include <bits/stdc++.h>
using namespace std;

// 解説AC1,メモ化再帰,O(n^2)

const int INF = (int)(1e9);
class Solution {
    vector<int> memo;
    int calc(vector<int>& nums, int pos=0) {
        int n = nums.size();
        if (pos >= n) return INF;
        if (memo[pos] != INF) return memo[pos];
        if (pos == n-1) return memo[pos] = 0;
        else {
            int res = INF;
            for (int i=1; i<=nums[pos]; ++i) {
                if (pos+i >= n) break;
                res = min(res, min(INF, calc(nums, pos+i)+1));
            }
            return memo[pos] = res;
        }
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        memo = vector<int>(n, INF);
        return calc(nums);
    }
};
