// 自力WA2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1e18);

int main() {
	while (1) {
		ll p;
		cin >> p;
		if (p == 0) break;
		vector<ll> plst;
		for (ll i=2; i*i<=p; ++i) {
			while (p%i == 0) {
				plst.push_back(i);
				p /= i;
			}
		}
		if (p > 1) plst.push_back(p);
		sort(plst.rbegin(), plst.rend());
		int plen = plst.size();
		vector<ll> glst(3, 1LL);
		rep(i, plen) {
			pair<ll, int> mid = { LINF, -1 };
			rep(j, 3) mid = min(mid, { glst[j], j });
			glst[mid.second] *= plst[i];
		}
		ll res = 0;
		rep(i, 3) res += glst[i];
		cout << res << endl;
	}
	return 0;
}
