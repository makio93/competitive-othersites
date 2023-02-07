#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;
        while (r-l >= 1) {
            int c = l + (r-l+1) / 2;
            int cnt = 0;
            for (int i=1; i<=n; ++i) cnt += min(m, (c-1)/i);
            if (k <= cnt) r = c-1;
            else l = c;
        }
        return l;
    }
};
