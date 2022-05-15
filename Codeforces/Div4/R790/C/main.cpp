// 

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
		vector<string> s(n);
		rep(i, n) cin >> s[i];
		int res = INF;
		rep(i, n) rep3(j, i+1, n) {
			int val = 0;
			rep(i2, m) val += abs(s[i][i2]-s[j][i2]);
			res = min(res, val);
		}
		cout << res << endl;
	}
	return 0;
}
