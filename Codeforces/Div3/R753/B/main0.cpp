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
		ll x, n;
		cin >> x >> n;
		ll res = x;
		if (n%4 >= 2) {
			if (x%2 == 0) ++res;
			else --res;
		}
		if (n%2 == 1) {
			if (res%2 == 0) res -= n;
			else res += n;
		}
		cout << res << endl;
	}
	return 0;
}
