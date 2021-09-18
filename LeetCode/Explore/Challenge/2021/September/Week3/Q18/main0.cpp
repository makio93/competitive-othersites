#include <bits/stdc++.h>
using namespace std;

// 自力AC

using ll = long long;
class Solution {
    const string tar = "+-*";
public:
    vector<string> addOperators(string num, int target) {
        int n = num.length();
        int lim = 1;
        for (int i=0; i<n-1; ++i) lim *= 4;
        vector<string> res;
        for (int i=0; i<lim; ++i) {
            string t;
            int ival = i;
            for (int j=0; j<n-1; ++j) {
                t += num[j];
                if (ival%4 < 3) t += tar[ival%4];
                ival /= 4;
            }
            t += num[n-1];
            ll sum = 0;
            int l = 0;
            int tlen = t.length();
            bool zok = true;
            while (l < tlen) {
                int l2 = l;
                while (l2+1<tlen && isdigit(t[l2+1])) ++l2;
                if (l2+1>=tlen || (l2<tlen&&t[l2+1]!='*')) {
                    ll val = stoll(t.substr(l,l2-l+1));
                    if (l2-l+1>1 && t[l]=='0') zok = false;
                    if (l-1<0 || (l-1>=0&&t[l-1]=='+')) sum += val;
                    else sum -= val;
                    l = l2 + 2;
                }
                else {
                    int r = l2;
                    ll val = stoll(t.substr(l,l2-l+1));
                    if (l2-l+1>1 && t[l]=='0') zok = false;
                    while (r+1<tlen && t[r+1]=='*') {
                        r += 2;
                        int r2 = r;
                        while (r2+1<tlen && isdigit(t[r2+1])) ++r2;
                        val *= stoll(t.substr(r,r2-r+1));
                        if (r2-r+1>1 && t[r]=='0') zok = false;
                        r = r2;
                    }
                    if (l-1<0 || (l-1>=0&&t[l-1]=='+')) sum += val;
                    else sum -= val;
                    l = r + 2;
                }
            }
            if (zok && sum==(ll)(target)) res.push_back(t);
        }
        return res;
    }
};
