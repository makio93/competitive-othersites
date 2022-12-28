// 本番TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

const int INF = (int)(1e9);
const int BMAX = (int)(1<<18);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<bool> checks(BMAX+1);
	vector<int> primes;
	for (int i=2; i*i<=BMAX; ++i) if (!checks[i]) {
		primes.push_back(i);
		for (int j=i*2; j<=BMAX; j+=i) checks[j] = true;
	}
	set<int> svals, nsvals;
	svals.insert(0);
	svals.insert(1);
	int m = primes.size();
	rep(i, m) {
		ll tval = (ll)primes[i] * primes[i];
		nsvals = svals;
		while (tval <= BMAX) {
			for (const int& vi : svals) {
				if (vi*tval > BMAX) break;
				nsvals.insert(vi*tval);
			}
			tval *= (ll)primes[i] * primes[i];
		}
		swap(svals, nsvals);
	}
	vector<int> slst(all(svals));
	int slen = slst.size();
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		map<int, int> acnt;
		acnt[0]++;
		ll res = (ll)n * (n+1) / 2;
		int mval = *max_element(all(a)), bval = 1;
		while (bval <= mval) bval <<= 1;
		int aval = 0;
		repr(i, n) {
			aval ^= a[i];
			rep(j, slen) {
				int xval = aval^slst[j];
				if (xval >= bval) break;
				if (acnt.find(xval) != acnt.end()) res -= acnt[xval];
			}
			acnt[aval]++;
		}
		cout << res << endl;
	}
	return 0;
}
