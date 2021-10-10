#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

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
		ll kval = 0;
		rep(i, n) kval += a[i];
		kval *= 2;
		if (kval%n != 0) {
			cout << 0 << endl;
			continue;
		}
		kval /= n;
		unordered_map<ll, int> rvals;
		ll res = 0;
		repr(i, n) {
			if (rvals.find(kval-a[i]) != rvals.end()) res += rvals[kval-a[i]];
			rvals[a[i]]++;
		}
		cout << res << endl;
	}
	return 0;
}
