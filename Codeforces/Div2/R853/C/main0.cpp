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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		rep(i, n) {
			cin >> a[i];
			a[i]--;
		}
		vector<int> acnt(n+m);
		rep(i, n) acnt[a[i]] = m+1;
		rep(i, m) {
			int pi, vi;
			cin >> pi >> vi;
			--pi; --vi;
			acnt[a[pi]] -= m - i;
			a[pi] = vi;
			acnt[a[pi]] += m - i;
		}
		ll res = (ll)m * (m+1) / 2 * n, add = 0;
		rep(i, n+m) if (acnt[i] > 0) {
			add += (ll)acnt[i] * (m+1 - acnt[i]);
		}
		res += add / 2;
		cout << res << endl;
	}
	return 0;
}