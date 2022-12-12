// 自力TLE,4-t

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
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		bool ok = false;
		unordered_map<int, int> pcnt;
		rep(i, n) {
			int ai = a[i];
			for (int j=2; j*j<=ai; ++j) if (ai%j == 0) {
				pcnt[j]++;
				if (pcnt[j] >= 2) {
					ok = true;
					break;
				}
				while (ai%j == 0) ai /= j;
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
