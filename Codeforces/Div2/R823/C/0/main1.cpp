// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> mvals(n+1, 9);
        repr(i, n) mvals[i] = min(mvals[i+1], s[i]-'0');
        string res;
        vector<int> buf(10);
        rep(i, n) {
            rep(j, mvals[i]) {
                res += string(buf[j], (char)(j+'0'));
                buf[j] = 0;
            }
            if (mvals[i] == s[i]-'0') res.push_back(s[i]);
            else buf[min(9,s[i]-'0'+1)]++;
        }
        rep(i, 10) res += string(buf[i], (char)(i+'0'));
        cout << res << endl;
    }
    return 0;
}
