#include <bits/stdc++.h>
using namespace std;

// 自力AC,staicなし解法2

using ll = long long;
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ll lval = stoll(left), rval = stoll(right);
        vector<ll> dstrs;
        int llen = max(0, (int)((to_string((ll)floor(sqrt(lval))).length()-1)/2)), 
            rlen = min(5, (int)((to_string((ll)ceil(sqrt(rval))).length()+1)/2));
        ll lten = 1, rten = 1;
        for (int i=0; i<llen; ++i) lten *= 10;
        for (int i=0; i<rlen; ++i) rten *= 10;
        for (ll ri=lten; ri<rten; ++ri) {
            string str = to_string(ri), rstr = str;
            reverse(rstr.begin(), rstr.end());
            vector<ll> tvals = { stoll(str+rstr), stoll(str+rstr.substr(1)) };
            if (tvals[0] == tvals[1]) tvals.pop_back();
            int tcnt = 0;
            for (ll val : tvals) {
                if (val < (ll)(1e18)/val) {
                    string tstr = to_string(val*val);
                    int lid = 0, rid = tstr.length() - 1;
                    bool ok = true;
                    while (lid < rid) {
                        if (tstr[lid] != tstr[rid]) {
                            ok = false;
                            break;
                        }
                        ++lid; --rid;
                    }
                    if (ok) dstrs.push_back(val*val);
                    ++tcnt;
                }
            }
            if (tcnt == 0) break;
        }
        sort(dstrs.begin(), dstrs.end());
        int lid = distance(dstrs.begin(), lower_bound(dstrs.begin(), dstrs.end(), lval)), 
            rid = distance(dstrs.begin(), upper_bound(dstrs.begin(), dstrs.end(), rval));
        return rid - lid;
    }
};
