#include <bits/stdc++.h>
using namespace std;

// 本番TLE

class Solution {
public:
    int maxProduct(string s) {
        int n = s.length(), mval = 1, res = 0;
        for (int i=0; i<n; ++i) mval *= 3;
        unordered_set<string> checked;
        for (int i=0; i<mval; ++i) {
            int tval = i;
            string t1, t2;
            for (int j=0; j<n; ++j) {
                if (tval%3 == 0) t1 += s[j];
                else if (tval%3 == 1) t2 += s[j];
                tval /= 3;
            }
            if ((int)(t1.length())*(int)(t2.length()) <= res) continue;
            if (checked.find((string)(t1+','+t2)) != checked.end()) continue;
            checked.insert((string)(t1+','+t2));
            checked.insert((string)(t2+','+t1));
            int l = 0, r = (int)(t1.length()) - 1;
            bool par = true;
            while (l < r) {
                if (t1[l] != t1[r]) {
                    par = false;
                    break;
                }
                ++l; --r;
            }
            if (par) {
                l = 0; r = (int)(t2.length()) - 1;
                while (l < r) {
                    if (t2[l] != t2[r]) {
                        par = false;
                        break;
                    }
                    ++l; --r;
                }
            }
            if (par) res = max(res, (int)(t1.length())*(int)(t2.length()));
            if (res == (n/2)*(n-n/2)) break;
        }
        return res;
    }
};
