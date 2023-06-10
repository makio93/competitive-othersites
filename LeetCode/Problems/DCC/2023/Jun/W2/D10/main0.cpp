// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int lv = 1, rv = maxSum+1;
        while (rv-lv > 1) {
            int cv = lv + (rv-lv) / 2;
            int li = max(0, index-(cv-1)), ri = min(n-1, index+(cv-1));
            ll val = (cv + cv-(index-li)) * (ll)(index-li+1) / 2 + (cv + cv-(ri-index)) * (ll)(ri-index+1) / 2 - cv + li + (n-1-ri);
            if (val <= maxSum) lv = cv;
            else rv = cv;
        }
        return lv;
    }
};
