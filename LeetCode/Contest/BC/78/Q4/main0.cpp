// 本番WA

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int res = 0;
        for (char ca='a'; ca<='z'; ++ca) for (char cb='a'; cb<='z'; ++cb) {
            int aval = 0, bval = 0, mval = 0;
            for (int i=0; i<n; ++i) {
                if (s[i] == ca) ++aval;
                else if (s[i] == cb) ++bval;
                if (aval!=0 && bval!=0) {
                    mval = min(mval, aval-bval);
                    if (aval==1 || bval==1) res = max({ res, aval-bval });
                    else res = max({ res, aval-bval, aval-bval-mval });
                }
            }
        }
        return res;
    }
};
