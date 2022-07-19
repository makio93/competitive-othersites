// 終了後,自力AC

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
		vector<int> a(n), b;
		rep(i, n) cin >> a[i];
		int zcnt = 0;
		while ((int)(a.size()) > 1) {
			int m = a.size();
			if (a[0] == 0) {
				int tcnt = 0;
				rep(i, m) if (a[i] == 0) ++tcnt;
				rep3(i, tcnt, m) b.push_back(a[i]);
				swap(b, a);
				zcnt += tcnt;
			}
			else {
				if (zcnt > 0) {
					--zcnt;
					b.push_back(a[0]);
				}
				rep(i, m-1) b.push_back(a[i+1]-a[i]);
				sort(all(b));
				swap(a, b);
			}
			b.clear();
		}
		if (a.empty()) cout << 0 << endl;
		else cout << a[0] << endl;
	}
	return 0;
}
