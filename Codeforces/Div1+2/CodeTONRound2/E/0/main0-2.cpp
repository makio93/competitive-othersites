// 自力,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;
const int INF = (int)(1e9);

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
		vector<int> din(n), dist(n, INF);
		vector<vector<int>> g(n);
		rep(i, m) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			g[xi].push_back(yi);
			din[yi]++;
		}
		vector<vector<pair<double, ll>>> tlst(n);
		rep(i, n) if (a[i] > 0) dist[i] = 0;
		queue<int> que;
		rep(i, n) if (din[i]==0 && a[i]>0) {
			que.push(i);
			tlst[i].emplace_back(0.0, 0);
			dist[i] = 1;
		}
		pair<double, ll> mval = { 0.0, 0 };
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			sort(all(tlst[vi]));
			int tlen = tlst[vi].size(), tcnt = tlen - 1;
			/*
			ll sval = ((a[0] == 0) ? (tlst[vi][0].second-dist[vi]+mod) : tlst[vi][0].second) % mod;
			double dsval = (a[0] == 0) ? (tlst[vi][0].first-dist[vi]) : tlst[vi][0].first;
			*/
			ll nval = ((ll)(tcnt * (tlst[vi][0].second-dist[vi]+mod)) + a[vi]) % mod;
			double dval = tcnt * (tlst[vi][0].first-dist[vi]) + a[vi];
			if (tcnt==0 && dval==0.0 && a[vi]==0) {
				nval = 1;
				dval = 1.0;
			}
			rep3(i, 1, tlen) {
				--tcnt;
				nval = (nval + (ll)(tcnt * (tlst[vi][i].second-tlst[vi][i-1].second+mod))) % mod;
				dval += (ll)(tcnt * (tlst[vi][i].first-tlst[vi][i-1].first));
			}
			nval = (nval + tlst[vi][tlen-1].second) % mod;
			dval += tlst[vi][tlen-1].first;
			mval = max(mval, { dval, nval });
			for (int ti : g[vi]) {
				tlst[ti].emplace_back(dval, nval);
				din[ti]--;
				if (din[ti] == 0) {
					que.push(ti);
					if (a[ti] > 0) dist[ti] = 0;
				}
				if (a[vi] == 0) dist[ti] = min(dist[ti], dist[vi]+1);
				else dist[ti] = min(dist[ti], 1);
			}
		}
		cout << mval.second << endl;
	}
	return 0;
}
