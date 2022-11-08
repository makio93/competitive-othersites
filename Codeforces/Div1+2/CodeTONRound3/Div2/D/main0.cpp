// 本番TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;
ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		vector<map<int, int>> plsts(n);
		auto pcalc = [&](int id) -> void {
			int aval = a[id];
			for (int i=2; i*i<=aval; ++i) if (aval%i == 0) {
				while (aval%i == 0) {
					aval /= i;
					plsts[id][i]++;
				}
			}
			if (aval > 1) plsts[id][aval] = 1;
		};
		ll res = 1;
		pcalc(0);
		rep3(i, 1, n) {
			ll gval = gcd(a[i-1], a[i]);
			if (gval != a[i]) {
				res = 0;
				break;
			}
			pcalc(i);
			vector<int> slst;
			for (const auto& pi : plsts[i]) if (plsts[i-1][pi.first] > pi.second) slst.push_back(pi.first);
			for (const auto& pi : plsts[i-1]) if (plsts[i].find(pi.first) == plsts[i].end()) slst.push_back(pi.first);
			sort(all(slst));
			slst.erase(unique(all(slst)), slst.end());
			int bi = slst.size();
			if (bi == 0) res = res * (m / a[i]) % mod;
			else {
				int sval = 0;
				ll tar = m / a[i];
				rep3(i1, 1, 1<<bi) {
					ll mval = 1;
					rep(j1, bi) if (i1&(1<<j1)) {
						mval *= slst[j1];
						if (mval > tar) break;
					}
					if (mval > tar) continue;
					if (__builtin_popcount(i1)%2 == 1) sval += tar / mval;
					else sval -= tar / mval;
				}
				res = res * (m/a[i] - sval) % mod;
			}
		}
		cout << res << endl;
	}
	return 0;
}
