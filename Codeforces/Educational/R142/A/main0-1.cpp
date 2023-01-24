// 本番WA

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
		vector<int> hsum(n+1);
		rep(i, n) hsum[i+1] += hsum[i] + h[i];
		int res = n;
		rep(i, n) {
			int vcnt = n - i - 1;
			if (hsum[i] >= h[i]) vcnt += hsum[i+1] / 2;
			else vcnt += h[i];
			res = min(res, vcnt);
		}
		cout << res << endl;
	}
	return 0;
}
