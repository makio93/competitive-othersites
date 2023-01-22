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
		vector<int> vcnt(m+1), a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		int acnt = 0, ri = 0, res = INF;
		auto add = [&](int id) -> void {
			for (int i=1; i*i<=a[id]; ++i) if (a[id]%i == 0) {
				if (i <= m) {
					vcnt[i]++;
					if (vcnt[i] == 1) ++acnt;
				}
				int i2 = a[id] / i;
				if (i == i2) continue;
				if (i2 <= m) {
					vcnt[i2]++;
					if (vcnt[i2] == 1) ++acnt;
				}
			}
		};
		auto del = [&](int id) -> void {
			for (int i=1; i*i<=a[id]; ++i) if (a[id]%i == 0) {
				if (i <= m) {
					vcnt[i]--;
					if (vcnt[i] == 0) --acnt;
				}
				int i2 = a[id] / i;
				if (i == i2) continue;
				if (i2 <= m) {
					vcnt[i2]--;
					if (vcnt[i2] == 0) --acnt;
				}
			}
		};
		rep(li, n) {
			while (ri<n && acnt<m) {
				add(ri);
				++ri;
			}
			if (acnt < m) break;
			res = min(res, a[ri-1]-a[li]);
			del(li);
		}
		if (res == INF) cout << -1 << endl;
		else cout << res << endl;
	}
	return 0;
}
