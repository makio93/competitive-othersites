#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

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
		int pos = 0, l = 0, r = 0;
		rep(i, n) {
			int tl = pos - a[i], tr = pos + a[i];
			if (tl>=l || tr<=r) {
				if (tl>=l && tr<=r) {
					if (tl-l <= r-tr) pos = tl;
					else pos = tr;
				}
				else if (tl>=l) pos = tl;
				else pos = tr;
			}
			else {
				if (l-tl <= tr-r) {
					l = min(l, tl);
					pos = tl;
				}
				else {
					r = max(r, tr);
					pos = tr;
				}
			}
		}
		cout << (r-l) << endl;
	}
	return 0;
}
