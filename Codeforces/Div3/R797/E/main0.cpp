// 本番AC

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a), [&](int vl, int vr) -> bool { return vl % k < vr % k; });
		int ri = n - 1;
		ll res = 0;
		vector<bool> used(n);
		rep(i, n) {
			if (i >= ri) break;
			if (a[i]%k+a[ri]%k >= k) {
				res += (a[i]+a[ri]) / k;
				used[i] = used[ri] = true;
				--ri;
			}
		}
		int cnt = 0, val = 0;
		rep(i, n) if (!used[i]) {
			val += a[i];
			used[i] = true;
			++cnt;
			if (cnt == 2) {
				res += val / k;
				val = 0;
				cnt = 0;
			}
		}
		cout << res << endl;
	}
	return 0;
}
