#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        string s;
        cin >> s;
        int n = s.length();
        vector<pair<char, int>> run;
        run.emplace_back(s.front(), 1);
        rep3(i, 1, n) {
            if (s[i] == run.back().first) run.back().second++;
            else run.emplace_back(s[i], 1);
        }
        int zcnt = 0, m = run.size();
        rep(i, m) if (run[i].first == '0') ++zcnt;
        if (zcnt >= 2) cout << 2 << endl;
        else if (zcnt == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
