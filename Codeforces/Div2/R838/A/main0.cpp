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
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int asum = accumulate(all(a), 0);
		if (asum%2 == 0) {
			cout << 0 << endl;
			continue;
		}
		int mval = INF;
		rep(i, n) {
			int cnt = 0, tval = a[i];
			while (tval!=0 && tval%2==a[i]%2) {
				++cnt;
				tval /= 2;
			}
			if (tval%2 != a[i]%2) mval = min(mval, cnt);
		}
		cout << mval << endl;
	}
	return 0;
}
