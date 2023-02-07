#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
public:
    int uniquePaths(int m, int n) {
        ll val = 1;
        int a = m + n - 2, b = min(m-1, n-1);
        for (int i=0; i<b; ++i) {
            val *= a-i;
            val /= i+1;
        }
        return (int)val;
    }
};
