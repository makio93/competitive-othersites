// 自力TLE1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n);
        int res = 0;
        function<void(int,int)> dfs = [&](int di, int val) {
            if (di == n/2) res = max(res, val);
            else {
                for (int li=0; li<n; ++li) if (!used[li]) {
                    used[li] = true;
                    for (int ri=li+1; ri<n; ++ri) if (!used[ri]) {
                        used[ri] = true;
                        dfs(di+1, val + gcd(nums[li], nums[ri]) * (di+1));
                        used[ri] = false;
                    }
                    used[li] = false;
                }
            }
        };
        dfs(0, 0);
        return res;
    }
};
