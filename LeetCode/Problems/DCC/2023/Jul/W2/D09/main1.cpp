// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int n = s.length(), res = 0;
        vector<int> ccnt(26);
        for (char ci='a'; ci<='z'; ++ci) ccnt[ci-'a'] = count(s.begin(), s.end(), ci);
        for (char ci='a'; ci<='z'; ++ci) for (char cj='a'; cj<='z'; ++cj) {
            int av = 0, bv = 0, rcnt = ccnt[cj-'a'];
            for (int i=0; i<n; ++i) {
                if (s[i] == ci) ++av;
                else if (s[i] == cj) {
                    ++bv;
                    --rcnt;
                }
                if (bv > 0) res = max(res, av-bv);
                if (av-bv < 0 && rcnt > 0) av = bv = 0;
            }
        }
        return res;
    }
};
