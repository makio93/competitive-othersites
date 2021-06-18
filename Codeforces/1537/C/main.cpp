#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		pair<int, int> mb = { (int)(1e9), -1 };
		rep3(i, 1, n) mb = min(mb, { a[i]-a[i-1], i-1 });
		vector<int> res;
		if (a[1]-a[0] == mb.first) {
			res.push_back(a[0]);
			rep3(i, 2, n) res.push_back(a[i]);
			res.push_back(a[1]);
		}
		else if (a[n-1]-a[n-2] == mb.first) {
			res.push_back(a[n-1]);
			rep(i, n-1) res.push_back(a[i]);
		}
		else {
			rep3(i, mb.second+1, n) res.push_back(a[i]);
			rep(i, mb.second+1) res.push_back(a[i]);
		}
		rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	}
	return 0;
}
