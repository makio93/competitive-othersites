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
		vector<int> rvals(n, n);
		rep(i, m) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			if (xi > yi) swap(xi, yi);
			rvals[xi] = min(rvals[xi], yi);
		}
		ll res = 0;
		int mval = n;
		repr(i, n) {
			mval = min(mval, rvals[i]);
			res += mval - i;
		}
		cout << res << endl;
	}
	return 0;
}
