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
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	dsu d(n);
	vector<int> dcnt(n);
	repr(i, m) {
		int nval = max(dcnt[d.leader(u[i])], dcnt[d.leader(v[i])]) + 1;
		d.merge(u[i], v[i]);
		dcnt[d.leader(u[i])] = nval;
	}
	int res = *max_element(all(dcnt));
	cout << res << endl;
	return 0;
}
