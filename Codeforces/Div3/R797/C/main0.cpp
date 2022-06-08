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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> s(n), f(n);
		rep(i, n) cin >> s[i];
		rep(i, n) cin >> f[i];
		int nval = 0;
		vector<int> res(n);
		rep(i, n) {
			nval = max(nval, s[i]);
			res[i] = f[i] - nval;
			nval = f[i];
		}
		rep(i, n) cout << res[i] << ' ';
		cout << endl;
	}
	return 0;
}
