#include <bits/stdc++.h>
using namespace std;

// 本番終了後,自力AC

class Solution {
public:
    int maxProduct(string s) {
        int n = s.length(), res = 0;
        unordered_set<string> parind, noparind;
        for (int i=1; i<(1<<n)-1; ++i) {
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
            int len = (int)(t2.length());
            if (parind.find(t2) != parind.end()) {
                res = max(res, (int)(t1.length())*len);
                continue;
            }
            int mval = 1;
            for (int j=1; j<(1<<len)-1; ++j) {
                string t3;
                for (int j2=0; j2<len; ++j2) if ((j>>j2)&1) t3 += t2[j2];
                int len2 = t3.length();
                if (parind.find(t3) != parind.end()) mval = max(mval, len2);
                else {
                    bool ok2 = true;
                    int l2 = 0, r2 = len2 - 1;
                    while (l2 < r2) {
                        if (t3[l2] != t3[r2]) {
                            ok2 = false;
                            break;
                        }
                        ++l2; --r2;
                    }
                    if (ok2) {
                        mval = max(mval, len2);
                        parind.insert(t3);
                    }
                    else noparind.insert(t3);
                }
            }
            res = max(res, (int)(t1.length())*mval);
        }
        return res;
    }
};
