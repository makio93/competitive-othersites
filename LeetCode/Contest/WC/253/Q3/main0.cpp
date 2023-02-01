#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int sub = -n-1, mval = 0, nval = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '[') ++nval;
            else --nval;
            mval = min(mval, nval);
        }
        sub = max(sub, mval);
        mval = nval = 0;
        for (int i=n-1; i>=0; --i) {
            if (s[i] == ']') ++nval;
            else --nval;
            mval = min(mval, nval);
        }
        sub = max(sub, mval);
        sub = min(0, sub);
        return (-(sub)+1) / 2;
    }
};
