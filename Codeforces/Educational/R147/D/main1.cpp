// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(2e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, k;
		cin >> n >> k;
		vector<int> l(n), r(n);
		rep(i, n) cin >> l[i];
		rep(i, n) cin >> r[i];
		int ccnt = 0, ssum = 0, res = INF;
		rep(i, n) {
			if (r[i]-l[i]+1 > 1) ssum += r[i]-l[i]+1;
			else ++ccnt;
			if (k > ssum+ccnt) continue;
			if (k > ssum) {
				int cval = k - ssum;
				res = min(res, ((i+1)-ccnt+cval)*2+r[i]);
			}
			else {
				res = min(res, ((i+1)-ccnt)*2+r[i]-(ssum-k));
				break;
			}
		}
		if (res == INF) cout << -1 << endl;
		else cout << res << endl;
	}
	return 0;
}
