// 自力AC,4

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
	int mval = (int)(round(sqrt(INF)));
	vector<bool> sie(mval+1);
	vector<int> primes;
	for (int i=2; i<=mval; ++i) {
		if (!sie[i]) {
			primes.push_back(i);
			for (int j=i*i; j<=mval; j+=i) sie[j] = true;
		}
	}
	int m = primes.size();
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		bool ok = false;
		vector<int> mcnt(m);
		unordered_map<int, int> pcnt;
		rep(i, n) {
			int ai = a[i];
			rep(j, m) if (ai%primes[j] == 0) {
				mcnt[j]++;
				if (mcnt[j] >= 2) {
					ok = true;
					break;
				}
				while (ai%primes[j] == 0) ai /= primes[j];
			}
			if (ok) break;
			if (ai > 1) {
				pcnt[ai]++;
				if (pcnt[ai] >= 2) {
					ok = true;
					break;
				}
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
