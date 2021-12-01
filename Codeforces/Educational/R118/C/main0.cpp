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
		int n;
		ll h;
		cin >> n >> h;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		ll l = 0, r = h;
		while (r-l > 1) {
			ll c = l + (r-l) / 2, val = 0;
			rep(i, n-1) val += min((ll)(a[i+1]-a[i]), c);
			val += c;
			if (val >= h) r = c;
			else l = c;
		}
		cout << r << endl;
	}
	return 0;
}
