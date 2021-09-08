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
        int n;
        string s;
        cin >> n >> s;
        vector<int> one, two;
        rep(i, n) {
            if (s[i] == '1') one.push_back(i);
            else two.push_back(i);
        }
        if ((int)(two.size())>0 && (int)(two.size())<3) {
            cout << "NO" << endl;
            continue;
        }
        vector<string> res(n, string(n, '='));
        rep(i, n) res[i][i] = 'X';
        int tlen = two.size();
        rep(i, tlen) {
            res[two[i]][two[(i+1)%tlen]] = '+';
            res[two[(i+1)%tlen]][two[i]] = '-';
        }
        cout << "YES" << endl;
        rep(i, n) cout << res[i] << endl;
    }
    return 0;
}
