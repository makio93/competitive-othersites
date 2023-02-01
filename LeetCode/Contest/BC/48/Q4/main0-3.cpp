// 自力TLE2

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n);
        int res = 0;
        for (int i1=0; i1<n/2; ++i1) {
            pair<int, pair<int, int>> mval = { 0, { -1, -1 } };
            for (int li=0; li<n; ++li) if (!used[li]) {
                used[li] = true;
                for (int ri=li+1; ri<n; ++ri) if (!used[ri]) {
                    used[ri] = true;
                    mval = max(mval, { gcd(nums[li], nums[ri]), make_pair(li, ri) });
                    used[ri] = false;
                }
                used[li] = false;
            }
            res += mval.first * (n/2-i1);
            used[mval.second.first] = used[mval.second.second] = true;
        }
        return res;
    }
};
