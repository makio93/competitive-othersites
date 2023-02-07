// 自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int uniquePaths(int m, int n) {
        ll res = 1;
        if (m > n) swap(m, n);
        for (int i=0; i<m-1; ++i) res = res * (m+n-2-i) / (i+1);
        return (int)res;
    }
};
