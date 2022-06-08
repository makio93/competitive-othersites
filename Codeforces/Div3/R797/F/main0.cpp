// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> p(n);
		rep(i, n) {
			cin >> p[i];
			p[i]--;
		}
		vector<bool> rcnt(n);
		vector<int> rlst;
		rep(i, n) if (!rcnt[i]) {
			int nval = i;
			string tmp;
			while (!rcnt[nval]) {
				rcnt[nval] = true;
				tmp.push_back(s[nval]);
				nval = p[nval];
			}
			int rlen = tmp.length(), rval = rlen;
			for (int j=1; j<=rlen; ++j) if (rlen%j == 0) {
				bool ok = true;
				string tar = tmp.substr(0, j);
				for (int i2=j; i2<rlen; i2+=j) if (tmp.substr(i2, j) != tar) {
					ok = false;
					break;
				}
				if (ok) {
					rval = min(rval, j);
					break;
				}
			}
			rlst.push_back(rval);
		}
		int m = rlst.size();
		ll res = rlst[0];
		rep3(i, 1, m) res = lcm(res, rlst[i]);
		cout << res << endl;
	}
	return 0;
}
