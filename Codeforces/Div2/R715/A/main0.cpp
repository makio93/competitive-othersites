// 本番AC

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
		vector<int> a(n), ans;
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<n; ++i) if (a[i]%2==1) ans.push_back(a[i]);
		for (int i=0; i<n; ++i) if (a[i]%2==0) ans.push_back(a[i]);
		for (int i=0; i<n; ++i) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
	}
	return 0;
}

