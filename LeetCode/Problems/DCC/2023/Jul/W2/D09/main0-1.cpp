// 自力WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int n = s.length(), res = 0;
        for (char ci='a'; ci<='z'; ++ci) for (char cj='a'; cj<='z'; ++cj) {
            int lv = 0, icnt = 0, jcnt = 0;
            for (int i=0; i<n; ++i) {
                if (s[i] == ci) ++icnt;
                else if (s[i] == cj) ++jcnt;
                lv = min(lv, jcnt-icnt);
                if (icnt>0 && jcnt>0) res = max(res, icnt-jcnt-lv);
            }
        }
        return res;
    }
};
