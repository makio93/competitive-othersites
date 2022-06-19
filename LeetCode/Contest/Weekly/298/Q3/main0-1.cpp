// 本番WA1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        if (s == string(n, '0')) return n;
        int bt = 1, bcnt = 1;
        while ((bt<<1) <= k) {
            bt <<= 1;
            ++bcnt;
        }
        bt <<= 1;
        if (n < bcnt) return n;
        bool bit = false;
        int zcnt = 0, val = 0;
        for (int i=0; i<bcnt; ++i) {
            val <<= 1;
            val += (s[i]-'0');
        }
        int res = bcnt - 1;
        if (val <= k) res = max(res, bcnt);
        for (int i=bcnt; i<n; ++i) {
            val <<= 1;
            if (s[i-bcnt] == '1') {
                val -= bt;
                zcnt = 0;
            }
            else ++zcnt;
            if (s[i] == '1') ++val;
            res = max(res, bcnt+zcnt);
        }
        return res;
    }
};
