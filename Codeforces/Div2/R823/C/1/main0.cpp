// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> mvals(10, -1);
        rep(i, n) mvals[s[i]-'0'] = max(mvals[s[i]-'0'], i);
        int id = 0;
        rep(i, 10) {
            if (mvals[i] == -1) continue;
            while (id <= mvals[i]) {
                if (s[id] != (char)(i+'0')) s[id] = (char)(min(9, s[id]-'0'+1) + '0');
                ++id;
            }
        }
        sort(all(s));
        cout << s << endl;
    }
    return 0;
}
