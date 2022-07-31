// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;

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
		vector<int> din(n);
		vector<vector<int>> g(n);
		rep(i, m) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			g[xi].push_back(yi);
			din[yi]++;
		}
		vector<vector<pair<double, ll>>> tlst(n);
		queue<int> que;
		rep(i, n) if (din[i] == 0) {
			que.push(i);
			tlst[i].emplace_back(0.0, 0);
		}
		pair<double, ll> mval = { 0.0, 0 };
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			sort(all(tlst[vi]));
			int tlen = tlst[vi].size(), tcnt = tlen - 1;
			ll nval = ((ll)(tcnt * tlst[vi][0].second) + a[vi]) % mod;
			double dval = tcnt * tlst[vi][0].first + a[vi];
			if (tcnt==0 && dval<(double)a[vi]) {
				nval = max(nval, (ll)a[vi]);
				dval = max(dval, (double)a[vi]);
			}
			rep3(i, 1, tlen) {
				--tcnt;
				nval = (nval + (ll)(tcnt * (tlst[vi][i].second-tlst[vi][i-1].second+mod))) % mod;
				dval += (ll)(tcnt * (tlst[vi][i].first-tlst[vi][i-1].first));
				if (tcnt==0 && dval<(double)a[vi]) {
					nval = max(nval, (ll)a[vi]);
					dval = max(dval, (double)a[vi]);
				}
			}
			nval = (nval + tlst[vi][tlen-1].second) % mod;
			dval += tlst[vi][tlen-1].first;
			mval = max(mval, { dval, nval });
			for (int ti : g[vi]) {
				tlst[ti].emplace_back(dval, nval);
				din[ti]--;
				if (din[ti] == 0) que.push(ti);
			}
		}
		cout << mval.second << endl;
	}
	return 0;
}
