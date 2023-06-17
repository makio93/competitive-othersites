// 本番AC

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
	int n, k;
	cin >> n >> k;
	vector<int> x(n+2), y(n+2);
	cin >> x[n] >> y[n] >> x[n+1] >> y[n+1];
	rep(i, n) cin >> x[i] >> y[i];
	int li = 0, ri = (int)(2e5);
	while (ri-li > 1) {
		int ci = ri - (ri-li) / 2;
		vector<vector<pair<int, int>>> g(n+2);
		rep(i, n+2) rep3(j, i+1, n+2) {
			int dist = abs(x[i]-x[j]) + abs(y[i]-y[j]), cost = (dist + ci - 1) / ci - 1;
			g[i].emplace_back(j, cost);
			g[j].emplace_back(i, cost);
		}
		vector<int> dp(n+2, INF);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		dp[n] = 0;
		pq.emplace(0, n);
		while (!pq.empty()) {
			auto [di, vi] = pq.top(); pq.pop();
			if (dp[vi] != di) continue;
			for (auto [ti, ncost] : g[vi]) {
				int ndi = di + ncost;
				if (dp[ti] <= ndi) continue;
				dp[ti] = ndi;
				pq.emplace(ndi, ti);
			}
		}
		if (dp[n+1] <= k) ri = ci;
		else li = ci;
	}
	cout << ri << endl;
	return 0;
}
