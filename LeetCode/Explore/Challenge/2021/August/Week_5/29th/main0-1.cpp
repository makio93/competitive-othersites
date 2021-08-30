#include <bits/stdc++.h>
using namespace std;

// 自力WA,1

class Solution {
    const int MAX = (int)(2e5);
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        vector<bool> vcnt(MAX+1);
        vcnt[0] = true;
        for (int i=0; i<m; ++i) vcnt[nums[i]] = true;
        int res = 0;
        while (1) {
            bool ok = true, zero = false;
            int mn = MAX+1, lcnt = 1;
            for (int i=1; i<=MAX; ++i) {
                if (vcnt[i]) {
                    ++lcnt;
                    if (zero && ok) ok = false;
                }
                else {
                    if (vcnt[i-1]) mn = min(mn, lcnt);
                    if (lcnt > 0) lcnt = 0;
                    if (!ok && !zero) zero = true;
                }
            }
            if (ok) break;
            for (int i=MAX-mn; i>=0; --i) if (vcnt[i]) vcnt[i+mn] = true;
            ++res;
        }
        int mval = 0;
        for (int i=0; i<=MAX; ++i) if (!vcnt[i]) {
            mval = i - 1;
            break;
        }
        if (mval < n) res += (long long)(n) / (mval + 1);
        return res;
    }
};
