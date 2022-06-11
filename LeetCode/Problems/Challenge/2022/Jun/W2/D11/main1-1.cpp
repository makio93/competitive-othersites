// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> lvals;
        int lval = 0;
        for (int i=0; i<=n; ++i) {
            lvals[lval] = i;
            if (i < n) lval += nums[i];
            if (lval > x) break;
        }
        int rval = 0, res = n+1;
        for (int i=n-1; i>=0; --i) {
            if (lvals.find(x-rval)!=lvals.end() && i+1>=lvals[x-rval]) res = min(res, lvals[x-rval]+n-i-1);
            rval += nums[i];
            if (rval > x) break;
        }
        if (res == n+1) res = -1;
        return res;
    }
};
