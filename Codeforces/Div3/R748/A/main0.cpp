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
		vector<int> vals(3);
		rep(i, 3) cin >> vals[i];
		vector<int> ans(3);
		rep(i, 3) {
			int mval = 0;
			rep(j, 3) if (j != i) mval = max(mval, vals[j]);
			ans[i] = max(0, (mval+1)-vals[i]);
		}
		rep(i, 3) cout << ans[i] << (i<2?' ':'\n');
	}
	return 0;
}
