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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		rep(i, n) rep(j, m) cin >> a[i][j];
		vector<vector<int>> ldp(n, vector<int>(m)), rdp(n, vector<int>(m));
		ldp[0][0] = rdp[0][0] = a[0][0];
		rep3(i, 1, n) ldp[i][0] = rdp[i][0] = ldp[i-1][0] + a[i][0];
		rep3(i, 1, m) ldp[0][i] = rdp[0][i] = ldp[0][i-1] + a[0][i];
		rep3(i, 1, n) rep3(j, 1, m) {
			ldp[i][j] = min(ldp[i-1][j], ldp[i][j-1]) + a[i][j];
			rdp[i][j] = max(rdp[i-1][j], rdp[i][j-1]) + a[i][j];
		}
		if (rdp[n-1][m-1]%2==0 && rdp[n-1][m-1]>=0 && ldp[n-1][m-1]<=0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
