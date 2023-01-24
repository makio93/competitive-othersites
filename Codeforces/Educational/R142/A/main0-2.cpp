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
		vector<int> h(n);
		rep(i, n) cin >> h[i];
		sort(all(h));
		int res = n, nval = 0;
		rep(i, n-1) {
			nval += h[i];
			h[i+1] -= h[i];
			h[i] = 0;
			if (i==n-2 && h[i+1]==0) res = min(res, nval);
			else res = min(res, nval+(n-1-i));
		}
		cout << res << endl;
	}
	return 0;
}
