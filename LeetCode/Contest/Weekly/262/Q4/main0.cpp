#include <bits/stdc++.h>
using namespace std;

// 本番参加1,WA

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), h = n / 2;
        int res = (int)(1e9), val1 = 0, val2 = 0;
        map<pair<int, int>, int> memo;
        function<void(int,int)> dfs = [&](int d, int ci) {
            if (memo.find({ d, ci }) != memo.end()) {
                if (memo[{d, ci}] < abs(val1-val2)) return;
                else memo[{d, ci}] = abs(val1-val2);
            }
            else memo[{d, ci}] = abs(val1-val2);
            if (d == n) res = min(res, abs(val1-val2));
            else {
                if (ci < h) {
                    val1 += nums[d];
                    dfs(d+1, ci+1);
                    val1 -= nums[d];
                }
                if (d-ci < h) {
                    val2 += nums[d];
                    dfs(d+1, ci);
                    val2 -= nums[d];
                }
            }
        };
        dfs(0, 0);
        return res;
    }
};
