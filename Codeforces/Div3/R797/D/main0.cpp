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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int res = INF, val = 0;
		rep(i, k) if (s[i] == 'W') ++val;
		res = min(res, val);
		rep3(i, k, n) {
			if (s[i] == 'W') ++val;
			if (s[i-k] == 'W') --val;
			res = min(res, val);
		}
		cout << res << endl;
	}
	return 0;
}
