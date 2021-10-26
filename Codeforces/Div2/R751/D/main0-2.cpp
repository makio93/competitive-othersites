#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<int> jp(n+1);
	rep(i, n) jp[i+1] = a[i+b[i]] - b[i];
	vector<int> dist(n+1, INF), from(n+1, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	dist[n] = 0;
	que.emplace(0, n);
	while (!que.empty()) {
		auto [d, v] = que.top(); que.pop();
		if (dist[v] != d) continue;
		int nd = d + 1;
		rep3(i, max(0,v-jp[v]), min(n,v+b[v])+1) {
			if (dist[i] > nd) {
				dist[i] = nd;
				from[i] = v;
				if (i > 0) que.emplace(nd, i);
			}
			else break;
		}
	}
	if (dist[0] == INF) cout << -1 << endl;
	else {
		vector<int> dlst;
		int dpos = 0;
		while (dpos != n) {
			dlst.push_back(dpos);
			dpos = from[dpos];
		}
		reverse(all(dlst));
		int m = dlst.size();
		cout << m << endl;
		rep(i, m) cout << (dlst[i]) << (i<m-1?' ':'\n');
	}
	return 0;
}
