// 本番WA3

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
		vector<ll> a(n), b(n);
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		repr(i, 30) {
			int acnt = 0, bcnt = 0;
			rep(j, n) {
				if ((a[j]>>i)&1) ++acnt;
				if ((b[j]>>i)&1) ++bcnt;
			}
			if (acnt+bcnt == n) {
				int mask = ((1<<30)-1) ^ ((1<<i)-1);
				sort(all(a), [&](int li, int ri) -> bool {
					return (li&mask) > (ri&mask);
				});
				sort(all(b), [&](int li, int ri) -> bool {
					return (li&mask) < (ri&mask);
				});
			}
			else {
				rep(j, n) {
					a[j] &= ~(1<<i);
					b[j] &= ~(1<<i);
				}
			}
		}
		ll res = (1LL<<30)-1;
		rep(i, n) res &= ((a[i])^(b[i]));
		cout << res << endl;
	}
	return 0;
}
