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
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		ll sum = 0;
		rep(i, n) sum += a[i];
		if (sum < (ll)(n)) cout << 1 << endl;
		else if (sum == (ll)(n)) cout << 0 << endl;
		else cout << (sum-(ll)(n)) << endl;
	}
	return 0;
}
