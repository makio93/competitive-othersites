#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,未完成

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		rep(i, n) cin >> a[i];
		int res = (int)(1e9);
		rep(i, n-4) {
			int val = 0, lval = 0, rval = 0;
			rep3(j, i+1, i+4) lval += 1 - (a[j][0]-'0');
			rep3(j, i+1, i+4) rval += 1 - (a[j][3]-'0');
			rep3(j, i+1, i+4) rep3(j2, 1, 3) val += a[j][j2] - '0';
			val += lval + rval;
			res = min(res, val);
			int rid = 3;
			rep(j, m-3) {
				while ()
			}
		}
	}
	return 0;
}
