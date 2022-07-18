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
		int n;
		cin >> n;
		vector<int> h(n);
		rep(i, n) cin >> h[i];
		ll res = 0;
		for (int i=1; i<n-1; i+=2) res += max(0, max(h[i-1],h[i+1])+1-h[i]);
		if (n%2 == 0) {
			ll nval = res;
			for (int i=n-3; i>=0; i-=2) {
				int lval = max(0, max(h[i-1],h[i+1])+1-h[i]), rval = max(0, max(h[i],h[i+2])+1-h[i+1]);
				nval += rval - lval;
				res = min(res, nval);
			}
		}
		cout << res << endl;
	}
	return 0;
}
