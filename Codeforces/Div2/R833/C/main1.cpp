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
		ll asum = 0;
		int res = 0, mval = 0;
		map<ll, int> scnt;
		bool fir = true;
		rep(i, n) {
			if (fir) {
				if (a[i] == 0) fir = false;
				else {
					asum += a[i];
					if (asum == 0) ++res;
				}
			}
			if (!fir) {
				if (a[i] == 0) {
					res += mval;
					mval = 0;
					scnt.clear();
				}
				asum += a[i];
				scnt[asum]++;
				mval = max(mval, scnt[asum]);
				if (i == n-1) res += mval;
			}
		}
		cout << res << endl;
	}
	return 0;
}
