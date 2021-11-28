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
		int n, e;
		cin >> n >> e;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		vector<vector<int>> b(e);
		rep(i, e) {
			for (int j=0; n-i-j-1>=0; j+=e) {
				int tmp = a[n-i-j-1], bval = -1;
				if (tmp == 1) bval = 0;
				else {
					vector<int> primes;
					for (int i2=2; i2*i2<=tmp; ++i2) if (tmp%i2 == 0) {
						primes.push_back(i2);
						if (i2 != tmp/i2) primes.push_back(tmp/i2);
					}
					if (primes.empty()) bval = 1;
				}
				b[i].push_back(bval);
			}
		}
		ll res = 0;
		rep(i, e) if ((int)(b[i].size()) > 1) {
			int m = b[i].size(), id0 = -1, id1 = -1;
			rep(j, m) {
				if (b[i][j] == -1) {
					id0 = -1;
					id1 = -1;
					continue;
				}
				if (b[i][j] == 0) {
					if (id0 == -1) id0 = j;
				}
				else if (b[i][j] == 1) {
					if (id1 != -1) {
						id0 = id1 + 1;
						id1 = j;
					}
					else if (id1 == -1) {
						id1 = j;
						if (id0 == -1) id0 = id1;
					}
				}
				if (id1==-1 || id0==-1) continue;
				if (id1 == j) res += max(0, id1-id0);
				else res += id1-id0+1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
