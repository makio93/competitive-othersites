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
		ll n, x;
		cin >> n >> x;
		if (n == x) {
			cout << x << endl;
			continue;
		}
		bool ok = true;
		int bid = -1, tid = INF;
		rep(i, 63) {
			if ((n&(1LL<<i)) != (x&(1LL<<i))) {
				if (((n>>i)&1LL) && !((x>>i)&1LL)) bid = i;
				else {
					ok = false;
					break;
				}
			}
			else if (((n>>i)&1LL) && tid==INF) tid = i;
		}
		if (bid+1<63 && (x&(1LL<<(bid+1)))) ok = false;
		if (tid < bid) ok = false;
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		ll tn = ((n >> bid) + 1) << bid;
		cout << tn << endl;
	}
	return 0;
}
