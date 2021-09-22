#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番後,自力AC

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
	int n, m;
	scanf("%d", &n);
	ll sum = 0;
	map<ll, int> acnt;
	rep(i, n) {
		ll ai;
		scanf("%lld", &ai);
		sum += ai;
		acnt[ai]++;
	}
	scanf("%d", &m);
	vector<ll> x(m), y(m);
	rep(i, m) scanf("%lld%lld", &x[i], &y[i]);
	vector<ll> ans(m);
	rep(i, m) {
		auto itr = acnt.lower_bound(x[i]);
		if (itr == acnt.end()) {
			ll res = (x[i]-(acnt.rbegin()->first)) + max(0LL, y[i]-(sum-(acnt.rbegin()->first)));
			ans[i] = res;
		}
		else if (sum-(itr->first) >= y[i]) ans[i] = 0;
		else {
			ll res = max(0LL, y[i]-(sum-(itr->first)));
			if (itr != acnt.begin()) {
				auto pitr = prev(itr);
				res = min(res, (x[i]-(pitr->first))+max(0LL,y[i]-(sum-(pitr->first))));
			}
			ans[i] = res;
		}
	}
	rep(i, m) printf("%lld\n", ans[i]);
	return 0;
}
