// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
    const ll mod = (ll)(1e16) + 7;
public:
    int deleteString(string s) {
        int n = s.length();
        vector<vector<ll>> hvals(n+1, vector<ll>(n+1));
        for (int i=0; i<n; ++i) {
            ll hval = 0;
            for (int j=i; j<n; ++j) {
                hval = (hval * 27 + (int)(s[j]-'a'+1)) % mod;
                hvals[i][j+1] = hval;
            }
        }
        int res = 0, li = 0;
        while (li < n) {
            int len = (n - li) / 2;
            bool ok = false;
            for (int i=len; i>0; --i) {
                if (hvals[li][li+i] == hvals[li+i][li+i+i]) {
                    ok = true;
                    if (s.substr(li, i) == string(i, s[li])) res += i;
                    else ++res;
                    li = li + i;
                    break;
                }
            }
            if (!ok) {
                ++res;
                li = n;
            }
        }
        return res;
    }
};
