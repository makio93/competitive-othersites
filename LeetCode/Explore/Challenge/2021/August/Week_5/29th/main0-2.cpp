#include <bits/stdc++.h>
using namespace std;

// 自力WA,2

class Solution {
    const int MAX = (int)(2e5);
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        vector<bool> vcnt(MAX+1);
        vcnt[0] = true;
        for (int i=0; i<m; ++i) vcnt[nums[i]] = true;
        int res = 0, mval = 0;
        for (int i=0; i<=MAX; ++i) if (vcnt[i]) mval = max(mval, i);
        while (1) {
            int mlen = 0;
            for (int i=0; i<=MAX; ++i) if (!vcnt[i]) {
                mlen = i;
                break;
            }
            if (mlen-1==mval || mlen-1>=n) break;
            for (int i=MAX-mlen; i>=0; --i) if (vcnt[i]) {
                vcnt[i+mlen] = true;
                mval = max(mval, i+mlen);
            }
            ++res;
        }
        if (mval < n) res += (long long)(n) / (mval + 1);
        return res;
    }
};
