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
		vector<int> a(n);
		int sum = 0;
		rep(i, n) {
			cin >> a[i];
			sum += a[i];
		}
		vector<int> deg(n);
		map<pair<int, int>, int> mcnt;
		rep(i, m) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			deg[xi]++;
			deg[yi]++;
			if (xi > yi) swap(xi, yi);
			mcnt[{ xi, yi }]++;
		}
		if (m%2 == 0) {
			cout << 0 << endl;
			continue;
		}
		vector<int> slst;
		rep(i, n) if (deg[i]%2 == 1) slst.push_back(a[i]);
		for (auto pi : mcnt) if (pi.second%2 == 1) slst.push_back(a[pi.first.first]+a[pi.first.second]);
		if (slst.empty()) {
			cout << sum << endl;
			continue;
		}
		sort(all(slst));
		cout << slst[0] << endl;
	}
	return 0;
}
