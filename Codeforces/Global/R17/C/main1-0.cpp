#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// ヒントのみから自力解答,WA

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i] >> b[i];
		int l = 1, r = n + 1;
		while (r-l > 1) {
			int c = l + (r-l) / 2;
			int cnt = 0;
			rep(i, n) if ((min(b[i],i)>=c-1-min(a[i],n-i-1)) && (min(a[i],n-i-1)>=c-1-min(b[i],i))) ++cnt;
			if (cnt >= c) l = c;
			else r = c;
		}
		cout << l << endl;
	}
	return 0;
}
