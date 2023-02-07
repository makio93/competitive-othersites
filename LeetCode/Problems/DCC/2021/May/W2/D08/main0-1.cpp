#include <bits/stdc++.h>
using namespace std;

// 自力AC,staticなし解法1

using ll = long long;
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ll lval = stoll(left), rval = stoll(right);
        int llen = max(1UL, left.length()/2), rlen = (right.length()+1) / 2 + 1, res = 0;
        ll lval2 = stoll(string("1")+string(max(1,llen/2-1)-1,'0')), rval2 = stoll(string((rlen+1)/2,'9'));
        for (ll ri=lval2; ri<=rval2; ++ri) {
            string str = to_string(ri), str1 = str, rstr1 = str;
            reverse(rstr1.begin(), rstr1.end());
            str1 += rstr1;
            ll dval = stoll(str1);
            if ((unsigned long long)dval <= (1ULL<<62)/dval) {
                string dstr = to_string(dval*dval);
                int lid = 0, rid = dstr.length() - 1;
                bool ok = true;
                while (lid < rid) {
                    if (dstr[lid] != dstr[rid]) {
                        ok = false;
                        break;
                    }
                    ++lid; --rid;
                }
                if (ok && stoll(dstr)>=lval && stoll(dstr)<=rval) ++res;
            }
            string str2 = str, rstr2 = str2;
            reverse(rstr2.begin(), rstr2.end());
            str2 += rstr2.substr(1);
            dval = stoll(str2);
            if ((unsigned long long)dval <= (1ULL<<62)/dval) {
                string dstr = to_string(dval*dval);
                int lid = 0, rid = dstr.length() - 1;
                bool ok = true;
                while (lid < rid) {
                    if (dstr[lid] != dstr[rid]) {
                        ok = false;
                        break;
                    }
                    ++lid; --rid;
                }
                if (ok && stoll(dstr)>=lval && stoll(dstr)<=rval) ++res;
            }
        }
        return res;
    }
};
