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
const int PMX = (int)(2e5);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	vector<int> vcnt(PMX);
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<vector<int>> c(n);
		rep(i, n) {
			int ki;
			cin >> ki;
			c[i].resize(ki);
			rep(j, ki) {
				cin >> c[i][j];
				c[i][j]--;
				vcnt[c[i][j]]++;
			}
		}
		bool ok = false;
		rep(i, n) {
			bool tok = true;
			for (const int& cj : c[i]) if (vcnt[cj] == 1) {
				tok = false;
				break;
			}
			if (tok) {
				ok = true;
				break;
			}
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
		rep(i, n) for (const int& cj : c[i]) vcnt[cj] = 0;
	}
	return 0;
}
