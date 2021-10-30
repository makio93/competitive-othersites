#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,未完成

const int NMAX = (int)(3e5) + 5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<bool> memo(NMAX+1);
	vector<int> pvals;
	rep3(i, 2, NMAX) {
		if (memo[i]) continue;
		pvals.push_back(i);
		for (int j=i*2; j<NMAX; j+=i) memo[j] = true;
	}
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		bool ok = true;
		rep(i, n) {
			set<int> primes, bprimes;
			int tval = a[i];
			for (int j=2; j*j<=tval; ++j) if (tval%j == 0) {
				if (j <= i+2) primes.insert(j);
				else bprimes.insert(j);
				while (tval%j == 0) tval /= j;
			}
			// 未完部分
			/*
			if (tval>1) {
				if (tval <= i+2) primes.insert(tval);
				else 
			}
			*/
			int di = upper_bound(all(pvals), i+2) - pvals.begin();
			if ((int)(primes.size()) >= di) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
