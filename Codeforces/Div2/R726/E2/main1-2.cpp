#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説WA,(Zアルゴリズムを用いた実装,失敗)

void zcalc(string& s, vector<int>& z) {
    int n = s.length();
    z[0] = n;
    int l = 1, r = 0;
    while (l < n) {
        while (l+r<n && s[l+r]==s[r]) ++r;
        z[l] = r;
        int ki = 1;
        while (ki < r) {
            if (z[ki] > r-ki) break;
            z[l+ki] = z[ki];
            ++ki;
        }
        l += ki;
        r -= ki;
    }
}

void printstr(string s, int k) {
    int len = 0, slen = s.length();
    string res;
    while (len < k) {
        res += s;
        len += slen;
    }
    cout << res.substr(0, k) << endl;
    exit(0);
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> z(n);
    zcalc(s, z);
    int rid = 1;
    rep3(i, 1, n) {
        if (s[i] > s[i%rid]) printstr(s.substr(0, rid), k);
        if (s[i] < s[i%rid]) {
            rid = i + 1;
            continue;
        }
        if (i-rid+1 == rid) {
            rid = i + 1;
            continue;
        }
        int aid = i - rid;
        if (z[aid] <= rid-aid-1) {
            if (s[z[aid]] < s[aid+z[aid]]) rid = i+1;
            continue;
        }
        int bid = rid - aid;
        if (z[bid] <= rid-bid-1) {
            if (s[bid+z[bid]] < s[z[bid]]) rid = i+1;
            continue;
        }
        rid = i + 1;
    }
    printstr(s.substr(0, rid), k);
    return 0;
}
