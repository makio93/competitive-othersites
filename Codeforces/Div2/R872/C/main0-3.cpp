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
		vector<int> x(n);
		rep(i, n) cin >> x[i];
		int lcnt = count(all(x), -1), rcnt = count(all(x), -2), res = min(m, max(lcnt, rcnt));
		if (lcnt+rcnt == n) {
			cout << res << endl;
			continue;
		}
		vector<int> xlst;
		rep(i, n) if (x[i] > 0) xlst.push_back(x[i]);
		sort(all(xlst));
		xlst.erase(unique(all(xlst)), xlst.end());
		vector<int> xsum(m+1);
		int len = xlst.size();
		rep(i, len) xsum[xlst[i]]++;
		rep(i, m) xsum[i+1] += xsum[i];
		rep(i, len) {
			int li = max(1, xlst[i]-lcnt-(xsum[xlst[i]-1]-xsum[0])), ri = min(m, xlst[i]+rcnt+(xsum[m]-xsum[xlst[i]]));
			res = max(res, min(m, ri-li+1));
			if (li == 1) {
				int sub = 1 - (xlst[i]-lcnt-(xsum[xlst[i]-1]-xsum[0])), tri = max(xlst[i]+1, m+1-sub-(xsum[m]-xsum[xlst[i]]));
				res = max(res, xlst[i]+(m+1)-tri);
			}
			if (ri == m) {
				int sub = (xlst[i]+rcnt+(xsum[m]-xsum[xlst[i]])) - m, tli = min(xlst[i]-1, sub+(xsum[xlst[i]-1]-xsum[0]));
				res = max(res, (m+1)-xlst[i]+tli);
			}
		}
		cout << res << endl;
	}
	return 0;
}
