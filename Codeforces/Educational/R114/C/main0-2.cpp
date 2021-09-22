#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番TLE2

int main() {
	int n, m;
	cin >> n;
	ull sum = 0;
	multiset<ull> acnt;
	rep(i, n) {
		ull ai;
		cin >> ai;
		sum += ai;
		acnt.insert(ai);
	}
	cin >> m;
	rep(i, m) {
		ull xi, yi;
		cin >> xi >> yi;
		auto itr = acnt.lower_bound(xi);
		if (itr == acnt.end()) {
			ull res = xi - (*acnt.rbegin());
			if (yi > sum-(*acnt.rbegin())) res += yi - (sum-(*acnt.rbegin()));
			cout << res << endl;
		}
		else if (sum-(*itr) >= yi) cout << 0LL << endl;
		else {
			ull res = 0ULL;
			if (yi > sum-(*itr)) res += yi - (sum-(*itr));
			if (itr != acnt.begin()) {
				ull res2 = xi - (*prev(itr));
				if (yi > sum-(*prev(itr))) res2 += yi - (sum-(*prev(itr)));
				res = min(res, res2);
			}
			cout << res << endl;
		}
	}
	return 0;
}
