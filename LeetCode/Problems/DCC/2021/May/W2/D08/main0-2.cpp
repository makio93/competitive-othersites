#include <bits/stdc++.h>
using namespace std;

// 自力AC,staticあり解法

using ll = long long;
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ll lval = stoll(left), rval = stoll(right);
        static vector<ll> dstrs;
        if (dstrs.empty()) {
            for (ll ri=1; ri<(ll)(1e5); ++ri) {
                string str = to_string(ri), rstr = str;
                reverse(rstr.begin(), rstr.end());
                vector<ll> tvals = { stoll(str+rstr), stoll(str+rstr.substr(1)) };
                if (tvals[0] == tvals[1]) tvals.pop_back();
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
                    }
                }
            }
            sort(dstrs.begin(), dstrs.end());
        }
        int lid = distance(dstrs.begin(), lower_bound(dstrs.begin(), dstrs.end(), lval)), 
            rid = distance(dstrs.begin(), upper_bound(dstrs.begin(), dstrs.end(), rval));
        return rid - lid;
    }
};
