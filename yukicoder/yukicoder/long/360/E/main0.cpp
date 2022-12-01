// 本番TLE

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<ll> a(n);
		rep(i, n) cin >> a[i];
		unordered_map<ll, int> pcnt;
		rep(i, n) {
			ll aval = a[i];
			for (ll i=2; i*i<=aval; ++i) {
				while (aval%i == 0) {
					pcnt[i]++;
					aval /= i;
				}
			}
			if (aval > 1) pcnt[aval]++;
		}
		bool ok = true;
		for (auto& pi : pcnt) if (pi.second%2 != 0) ok = false;
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
