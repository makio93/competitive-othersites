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
		ll n;
		cin >> n;
		ll nval = n * 2;
		ll dval = 1, rval = -1;
		while (rval == -1) {
			ll tval = nval / dval - dval;
			if (tval%2 == 1) rval = tval;
			else do { ++dval; } while (nval%dval != 0);
		}
		ll bval = (rval - 1) / 2, aval = dval + bval;
		++bval;
		if (bval == aval) bval = -(bval-1);
		else if (bval > aval) swap(bval, aval);
		cout << bval << ' ' << aval << endl;
	}
	return 0;
}
