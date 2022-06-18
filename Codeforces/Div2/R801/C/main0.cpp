// 本番AC

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
		if ((n+m-1)%2 == 1) {
			cout << "NO" << endl;
			continue;
		}
		vector<vector<int>> ldp(n, vector<int>(m, INF)), rdp(n, vector<int>(m, -INF));
		ldp[0][0] = rdp[0][0] = a[0][0];
		rep(i, n) rep(j, m) {
			if (j+1 < m) {
				ldp[i][j+1] = min(ldp[i][j+1], ldp[i][j]+a[i][j+1]);
				rdp[i][j+1] = max(rdp[i][j+1], rdp[i][j]+a[i][j+1]);
			}
			if (i+1 < n) {
				ldp[i+1][j] = min(ldp[i+1][j], ldp[i][j]+a[i+1][j]);
				rdp[i+1][j] = max(rdp[i+1][j], rdp[i][j]+a[i+1][j]);
			}
		}
		if (ldp[n-1][m-1]<=0 && rdp[n-1][m-1]>=0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
