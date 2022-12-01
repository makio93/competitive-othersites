#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int res = 0;
	rep3(i, 1, (1<<n)) {
		unordered_set<ll> bval;
		bval.insert(0);
		ll sum = 0;
		rep(j, n) if ((i>>j)&1) {
			unordered_set<ll> nbval;
			for (ll bi : bval) {
				nbval.insert(bi+a[j]);
				nbval.insert(bi+a[j]/2);
			}
			swap(nbval, bval);
		}
		if (bval.find((ll)w) != bval.end()) ++res;
	}
	cout << res << endl;
	return 0;
}
