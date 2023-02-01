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
		int res = 0;
		if (asum == n) res = asum - 4;
		else {
			bool neg = false;
			rep(i, n-1) if (a[i]==-1 && a[i+1]==-1) {
				neg = true;
				break;
			}
			if (neg) res = asum + 4;
			else res = asum;
		}
		cout << res << endl;
	}
	return 0;
}
