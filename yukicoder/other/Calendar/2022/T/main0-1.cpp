// 本番WA1

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
		int n;
		ll w;
		cin >> n >> w;
		vector<ll> wi(n);
		rep(i, n) cin >> wi[i];
		vector<ll> fib(n);
		rep(i, n) {
			if (i == 0) fib[i] = 1;
			else if (i == 1) fib[i] = 2;
			else fib[i] = fib[i-2] + fib[i-1];
		}
		ll fsum = accumulate(all(fib), 0LL), lval = 0, rval = fsum + 1;
		while (rval-lval > 1) {
			ll cval = lval + (rval-lval) / 2, tval = cval;
			vector<bool> used(n);
			repr(i, n) {
				if (tval >= fib[i]) {
					tval -= fib[i];
					used[i] = true;
				}
			}
			rep3(i, 2, n) if (used[i] && !used[i-2] && !used[i-1]) {
				if (wi[i] >= wi[i-2]+wi[i-1]) {
					used[i] = false;
					used[i-2] = used[i-1] = true;
				}
			}
			ll wsum = 0;
			rep(i, n) if (used[i]) wsum += wi[i];
			if (wsum <= w) lval = cval;
			else rval = cval;
		}
		cout << lval << endl;
	}
	return 0;
}
