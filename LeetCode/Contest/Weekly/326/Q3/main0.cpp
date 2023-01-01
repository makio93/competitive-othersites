// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.length();
        ll nval = 0;
        int res = 0;
        for (int i=0; i<n; ++i) {
            if (nval*10+(s[i]-'0') <= k) nval = nval * 10 + (s[i]-'0');
            else if ((s[i]-'0') > k) {
                res = -1;
                break;
            }
            else {
                ++res;
                nval = (s[i]-'0');
            }
        }
        if (res == -1) return res;
        return res + 1;
    }
};
