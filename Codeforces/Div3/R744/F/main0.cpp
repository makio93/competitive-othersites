#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		if (a == vector<int>(n, 0)) {
			cout << 0 << endl;
			continue;
		}
		int r = (int)gcd(n, d);
		bool ok = true;
		int res = 0;
		rep(i, r) {
			vector<int> b;
			for (int j=i; j<n; j+=r) b.push_back(a[j]);
			int m = b.size();
			if (b == vector<int>(m, 1)) {
				ok = false;
				break;
			}
			if (b == vector<int>(m, 0)) continue;
			int ri = d / r;
			queue<int> que;
			vector<int> dist(m, (int)(1e9));
			rep(j, m) if (b[j] == 0) {
				que.push(j);
				dist[j] = 0;
			}
			while (!que.empty()) {
				int v = que.front(); que.pop();
				int dj = dist[v], ndj = dj + 1;
				int tv = (v + ri) % m;
				if (dist[tv] > ndj) {
					que.push(tv);
					dist[tv] = ndj;
				}
			}
			int val = 0;
			rep(j, m) val = max(val, dist[j]);
			res = max(res, val);
		}
		if (!ok) cout << -1 << endl;
		else cout << res << endl;
	}
	return 0;
}
