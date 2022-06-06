// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int totalNQueens(int n) {
        ll flag = 0;
        auto dfs = [&](auto dfs, int d=0) -> int {
            if (d == n) return 1;
            else {
                int val = 0;
                for (int i=0; i<n; ++i) if (!((flag>>i)&1) && !((flag>>(n+d+i))&1) && !((flag>>(4*n-2+d-i))&1)) {
                    flag |= 1LL<<i; flag |= 1LL<<(n+d+i); flag |= 1LL<<(4*n-2+d-i);
                    val += dfs(dfs, d+1);
                    flag &= ~(1LL<<i); flag &= ~(1LL<<(n+d+i)); flag &= ~(1LL<<(4*n-2+d-i));
                }
                return val;
            }
        };
        return dfs(dfs);
    }
};
