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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int a, b, c, m;
		cin >> a >> b >> c >> m;
		int mval = max({ a, b, c }), lval = max(0, mval-(a+b+c-mval+1)), rval = a + b + c - 3;
		if (m>=lval && m<=rval) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
