#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, m;
	cin >> n;
	ll sum = 0;
	map<ll, int> acnt;
	rep(i, n) {
		ll ai;
		cin >> ai;
		sum += ai;
		acnt[ai]++;
	}
	map<pair<ll,ll>, ll> memo;
	cin >> m;
	rep(i, m) {
		ll xi, yi;
		cin >> xi >> yi;
		if (memo.find({xi,yi}) != memo.end()) {
			cout << memo[{xi,yi}] << endl;
			continue;
		}
		auto itr = acnt.lower_bound(xi);
		if (itr == acnt.end()) {
			ll res = (xi-(acnt.rbegin()->first)) + max(0LL, yi-(sum-(acnt.rbegin()->first)));
			cout << res << endl;
			memo[{xi,yi}] = res;
			continue;
		}
		if (sum-(itr->first) >= yi) {
			cout << 0 << endl;
			memo[{xi,yi}] = 0;
			continue;
		}
		ll res = max(0LL, yi-(sum-(itr->first)));
		if (itr != acnt.begin()) res = min(res, (xi-(prev(itr)->first))+max(0LL,yi-(sum-(prev(itr)->first))));
		cout << res << endl;
		memo[{xi,yi}] = res;
	}
	return 0;
}
