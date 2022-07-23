// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	int l = 0, tb = 1;
	while (tb <= m) {
		++l;
		tb *= 2;
	}
	vector<vector<int>> st(l, vector<int>(m));
	rep(i, m) st[0][i] = a[i];
	rep3(i, 1, l) rep(j, m) {
		st[i][j] = st[i-1][j];
		if (j+(1<<i) < m) st[i][j] = max(st[i][j], st[i-1][j+(1<<(i-1))]);
	}
	vector<int> tpw(m+1);
	rep3(i, 2, m+1) tpw[i] = tpw[i/2] + 1;
	auto stget = [&](int li, int ri) -> int {
		if (ri-li <= 0) return 0;
		int len = tpw[ri-li];
		return max(st[len][li], st[len][ri-(1<<len)]);
	};
	int q;
	cin >> q;
	rep(i, q) {
		int xs, ys, xf, yf, ki;
		cin >> xs >> ys >> xf >> yf >> ki;
		--xs; --ys; --xf; --yf;
		if (xs%ki!=xf%ki || ys%ki!=yf%ki) {
			cout << "NO" << endl;
			continue;
		}
		int mx = (n-xs-1) / ki * ki + xs;
		if (yf < ys) swap(ys, yf);
		if (stget(ys, yf+1) <= mx) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
