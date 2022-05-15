// 終了後,自力,WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int res = 0;
        for (char a='a'; a<='z'; ++a) for (char b='a'; b<='z'; ++b) if (a != b) {
            int acnt = 0, bcnt = 0;
            pair<int, pair<int, int>> pval = { 0, { 0, 0 } };
            for (int i=0; i<n; ++i) {
                if (s[i] == a) ++acnt;
                if (s[i] == b) ++bcnt;
                if (acnt>0 && bcnt>0) res = max(res, acnt-bcnt);
                if (acnt!=pval.second.first && bcnt!=pval.second.second) res = max(res, (acnt-bcnt)-pval.first);
                pval = min(pval, { acnt-bcnt, { acnt, bcnt } });
            }
        }
        return res;
    }
};
