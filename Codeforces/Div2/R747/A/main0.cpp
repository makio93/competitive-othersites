#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll n;
		cin >> n;
		ll nval = n * 2;
		ll aval = sqrt(nval);
		while (aval*(aval+1) < nval) ++aval;
		ll bval = -1;
		while (bval == -1) {
			ll tval = aval * (aval+1) - nval;
			ll tval2 = sqrt(tval);
			while (tval2*(tval2+1) < tval) ++tval2;
			if (tval2*(tval2+1) == tval) bval = tval2;
			else ++aval;
		}
		++bval;
		if (bval == aval) bval = -(bval-1);
		cout << bval << ' ' << aval << endl;
	}
	return 0;
}
