#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(5));
		rep(i, n) rep(j, 5) cin >> a[i][j];
		bool ok = false;
		rep(i1, 5) {
			rep3(j1, i1+1, 5) {
				bool br = false;
				vector<int> cnt(3);
				rep(i, n) {
					if (a[i][i1]==1 && a[i][j1]==1) cnt[2]++;
					else if (a[i][i1] == 1) cnt[0]++;
					else if (a[i][j1] == 1) cnt[1]++;
					else {
						br = true;
						if (br) break;
					}
				}
				if (br) continue;
				if (max(0,n/2-cnt[0])+max(0,n/2-cnt[1]) <= cnt[2]) {
					ok = true;
					break;
				}
			}
			if (ok) break;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
