// 終了後,自力,WA

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
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(n));
		rep(i, n) rep(j, n) cin >> a[i][j];
		rep(i, n) {
			bool sec = true;
			if (i > 0) {
				vector<int> slst, tlst;
				rep(j, i) {
					slst.push_back(a[j][i]);
					tlst.push_back(a[i][j]);
				}
				if (slst != tlst) {
					sec = false;
					if (slst > tlst) rep(j, n) swap(a[j][i], a[i][j]);
				}
			}
			if (sec && i<n-1) {
				vector<int> slst, tlst;
				rep3(j, i+1, n) {
					slst.push_back(a[j][i]);
					tlst.push_back(a[i][j]);
				}
				if (tlst > slst) rep(j, n) swap(a[j][i], a[i][j]);
			}
		}
		rep(i, n) rep(j, n) cout << a[i][j] << (j<n-1?' ':'\n');
	}
	return 0;
}
