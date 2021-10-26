#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

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
		vector<int> res;
		if (a == vector<int>(n, 0)) rep3(i, 1, n+1) res.push_back(i);
		else {
			vector<int> bcnt(30);
			rep(i, n) rep(j, 30) if ((a[i]>>j)&1) bcnt[j]++;
			ll gval = 0;
			rep(i, 30) if (bcnt[i] != 0) {
				if (gval == 0) gval = bcnt[i];
				else gval = gcd(gval, bcnt[i]);
			}
			for (int i=1; i*i<=gval; ++i) if (gval%i == 0) {
				res.push_back(i);
				if (i != gval/i) res.push_back(gval/i);
			}
			sort(all(res));
		}
		int m = res.size();
		rep(i, m) cout << res[i] << (i<m-1?' ':'\n');
	}
	return 0;
}
