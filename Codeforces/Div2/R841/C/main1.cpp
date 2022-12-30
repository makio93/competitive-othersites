// 解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const int BMAX = (int)(1<<18);

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
		ll res = (ll)n * (n+1) / 2;
		vector<int> vcnt(n*2);
		int nval = 0;
		vcnt[nval]++;
		rep(i, n) {
			nval ^= a[i];
			for (int j=0; j*j<n*2; ++j) if ((nval^(j*j)) < n*2) res -= vcnt[nval^(j*j)];
			vcnt[nval]++;
		}
		cout << res << endl;
	}
	return 0;
}
