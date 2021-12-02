#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番終了後,自力AC

const vector<int> corps = { 1, 4, 6, 8, 9 }, primes = { 2, 3, 5, 7 };

int main() {
    int ti;
    cin >> ti;
    rep(i0, ti) {
        int k;
        string n;
        cin >> k >> n;
        string res;
        vector<int> dcnt(10);
        rep(i, k) dcnt[n[i]-'0']++;
        for (int ci : corps) if (dcnt[ci] > 0) {
            res += (char)(ci+'0');
            break;
        }
        if (!res.empty()) {
            cout << (int)(res.length()) << endl;
            cout << res << endl;
            continue;
        }
        for (int pi : primes) if (dcnt[pi] >= 2) {
            res = string(2, (char)(pi+'0'));
            break;
        }
        if (!res.empty()) {
            cout << (int)(res.length()) << endl;
            cout << res << endl;
            continue;
        }
        int len = min(k, 4);
        pair<int, string> mval = { k+1, "" };
        rep3(i, 1, (1<<len)) {
            string t;
            rep(j, len) if ((i>>j)&1) t += n[j];
            vector<ll> pvals;
            ll tval = stoll(t), tmp = tval;
            for (ll a=2; a*a<=tmp; ++a) {
                while (tmp%a == 0) {
                    tmp /= a;
                    pvals.push_back(a);
                }
            }
            if (tmp > 1) pvals.push_back(tmp);
            if ((int)(pvals.size()) > 1) mval = min(mval, { (int)(t.length()), t });
        }
        res = mval.second;
        cout << (int)(res.length()) << endl;
        cout << res << endl;
    }
    return 0;
}
