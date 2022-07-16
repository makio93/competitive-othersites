// 

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int li = 0;
		while (li<n-1 && a[li]==0) ++li;
		if (li == n-1) {
			cout << 0 << endl;
			continue;
		}
		int ri = li;
		while (ri<n-1 && a[ri]>0) ++ri;
		ll res = 0;
		while (ri < n-1) {
			while (a[li] == 0) ++li;
			a[li]--;
			a[ri]++;
			++res;
			while (ri<n-1 && a[ri]>0) ++ri;
		}
		while (a[li] == 0) ++li;
		rep3(i, li, n-1) res += a[i];
		cout << res << endl;
	}
	return 0;
}
