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
		int n, m;
		cin >> n >> m;
		vector<int> b(n*m);
		rep(i, n*m) cin >> b[i];
		sort(all(b));
		int fir = b.back() - b.front(), sec = fir - min(b[1]-b[0], b[n*m-1]-b[n*m-2]);
		if (n > m) swap(n, m);
		ll res = (n-1) * (ll)sec + (m-1) * n * (ll)fir;
		cout << res << endl;
	}
	return 0;
}
