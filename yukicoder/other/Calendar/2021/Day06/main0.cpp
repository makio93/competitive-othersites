#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番参加,解答不能

int main() {
	int n, m;
	cin >> n >> m;
	vector<set<int>> g(n+2);
	rep(i, n) {
		g[2+i].insert(2+(i+1)%n);
		g[2+(i+1)%n].insert(2+i);
		g[2+i].insert(0);
		g[0].insert(2+i);
	}
	vector<int> u(m), v(m);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	map<int, set<int>> edges;
	rep(i, m) edges[u[i]].insert(v[i]);
	set<int> center;
	rep(i, n) center.insert(2+i);
	for (auto pi : edges) {
		// 構築処理,解答不能
	}
	return 0;
}
