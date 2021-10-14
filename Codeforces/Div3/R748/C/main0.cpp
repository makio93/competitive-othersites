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
		int n, k;
		cin >> n >> k;
		vector<int> x(k);
		rep(i, k) cin >> x[i];
		sort(all(x));
		int rid = k-1, cval = 0;
		while (rid>=0 && x[rid]>cval) {
			cval += n - x[rid];
			--rid;
		}
		int res = (k-1) - rid;
		cout << res << endl;
	}
	return 0;
}
