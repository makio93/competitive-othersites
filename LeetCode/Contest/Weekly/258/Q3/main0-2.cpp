#include <bits/stdc++.h>
using namespace std;

// 本番WA

class Solution {
public:
    int maxProduct(string s) {
        int n = s.length(), res = 0;
        unordered_set<string> parind, noparind;
        for (int i=0; i<(1<<n); ++i) {
            string t1, t2;
            for (int j=0; j<n; ++j) {
                if ((i>>j)&1) t1 += s[j];
                else t2 += s[j];
            }
            if (noparind.find(t1) != noparind.end()) continue;
            bool ok1 = true;
            if (parind.find(t1) == noparind.end()) {
                int l1 = 0, r1 = (int)(t1.length()) - 1;
                while (l1 < r1) {
                    if (t1[l1] != t1[r1]) {
                        ok1 = false;
                        break;
                    }
                    ++l1; --r1;
                }
            }
            if (!ok1) {
                noparind.insert(t1);
                continue;
            }
            parind.insert(t1);
            int len = (int)(t2.length()), mval = -1;
            if (parind.find(t2) != parind.end()) mval = len;
            else {
                for (int i1=len-1; i1>=1; --i1) {
                    for (int i2=0; i2+i1<len; ++i2) {
                        int l2 = i2, r2 = l2 + i1;
                        bool ok2 = true;
                        while (l2 < r2) {
                            if (t2[l2] != t2[r2]) {
                                ok2 = false;
                                break;
                            }
                            ++l2; --r2;
                        }
                        if (ok2) {
                            mval = max(mval, i1+1);
                            break;
                        }
                    }
                    if (mval != -1) break;
                }
                if (mval == -1) mval = 1;
            }
            res = max(res, (int)(t1.length())*mval);
        }
        return res;
    }
};
