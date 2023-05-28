// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        ll res = 0;
        for (int i=0; i<n-1; ++i) if (s[i+1] != s[i]) res += min(i+1, n-i-1);
        return res;
    }
};
