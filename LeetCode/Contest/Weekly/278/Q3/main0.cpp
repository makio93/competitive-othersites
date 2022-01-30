#include <bits/stdc++.h>
using namespace std;

// 本番WA1

using ll = long long;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashvalue) {
        int n = s.length();
        vector<ll> hvals(n+1);
        ll r = 1;
        for (int i=0; i<n; ++i) {
            hvals[i+1] = (hvals[i] + (ll)(s[i]-'a'+1) * r) % modulo;
            r = r * power % modulo;
        }
        int rid = -1;
        r = 1;
        for (int i=0; i+k<n+1; ++i) {
            ll hval = hvals[i+k] - hvals[i];
            if (hval < 0) hval += modulo;
            if (hval == (ll)hashvalue*r%modulo) {
                rid = i;
                break;
            }
            r = r * power % modulo;
        }
        if (rid == -1) return "a";
        return s.substr(rid, k);
    }
};
