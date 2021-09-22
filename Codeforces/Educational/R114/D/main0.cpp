#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 

int main() {
	int n, m;
	cin >> n;
	vector<int> c(n);
	vector<vector<int>> a(n);
	rep(i, n) {
		cin >> c[i];
		vector<int> ai(c[i]);
		rep(j, c[i]) cin >> ai[j];
		a[i] = ai;
	}
	cin >> m;
	vector<vector<int>> b(m, vector<int>(n));
	rep(i, m) {
		rep(j, n) {
			cin >> b[i][j];
			b[i][j]--;
		}
	}
	set<vector<int>> btar;
	rep(i, m) btar.insert(b[i]);
	priority_queue<pair<ll, vector<int>>> que;
	ll val = 0;
	vector<int> blst(n);
	rep(i, n) {
		val += a[i].back();
		blst[i] = c[i] - 1;
	}
	vector<int> res;
	que.emplace(val, blst);
	while (!que.empty()) {
		auto [v, bl] = que.top(); que.pop();
		if (btar.find(bl) == btar.end()) {
			res = bl;
			break;
		}
		rep(i, n) if (bl[i]-1 >= 0) {
			vector<int> nbl = bl;
			nbl[i]--;
			ll nval = 0;
			rep(j, n) nval += a[j][nbl[j]];
			que.emplace(nval, nbl);
		}
	}
	rep(i, n) printf("%d%c", (res[i]+1), (i<n-1?' ':'\n'));
	return 0;
}
