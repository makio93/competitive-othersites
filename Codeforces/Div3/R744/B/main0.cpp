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
		int n;
		cin >> n;
		vector<int> a(n), b;
		rep(i, n) cin >> a[i];
		b = a;
		sort(all(b));
		vector<tuple<int, int, int>> res;
		repr(i, n) repr(j, i+1) if (a[j] == b[i]) {
			if (i != j) {
				res.emplace_back(j+1, i+1, 1);
				rep3(j2, j, i) a[j2] = a[j2+1];
				a[i] = b[i];
			}
			break;
		}
		int k = res.size();
		cout << k << endl;
		rep(i, k) cout << get<0>(res[i]) << ' ' << get<1>(res[i]) << ' ' << get<2>(res[i]) << endl;
	}
	return 0;
}
