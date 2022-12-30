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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<ll> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		a.erase(unique(all(a)), a.end());
		if ((int)(a.size()) < n) {
			cout << "NO" << endl;
			continue;
		}
		bool ok = true;
		rep3(i, 2, n+1) {
			vector<int> mcnt(i);
			rep(j, n) mcnt[a[j]%i]++;
			bool tok = false;
			rep(j, i) if (mcnt[j] < 2) tok = true;
			if (!tok) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
