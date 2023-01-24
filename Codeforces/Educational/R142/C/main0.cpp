// 本番AC

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
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> p(n);
		rep(i, n) cin >> p[i];
		int li = 0;
		rep(i, n) if (p[i] == n/2) {
			li = i;
			break;
		}
		int ri = li + 1, nval = n / 2;
		if (n%2 == 1) while (ri<n && p[ri]!=n/2+1) ++ri;
		while (li>=0 && nval>=1) {
			while (ri<n && p[ri]!=n+1-nval) ++ri;
			if (ri >= n) break;
			--nval;
			while (li>=0 && p[li]!=nval) --li;
		}
		int res = nval;
		cout << res << endl;
	}
	return 0;
}
