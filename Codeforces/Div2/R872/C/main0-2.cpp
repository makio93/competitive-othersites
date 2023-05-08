// 本番WA2

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
			int li = max(1, xlst[i]-lcnt), ri = min(m, xlst[i]+rcnt);
			res = max(res, ri-li+1+(xsum[m]-xsum[ri])+(xsum[li-1]-xsum[0]));
			if (ri-li+1 < n) {
				if (li == 1) {
					int sub = 1 - xlst[i]-lcnt, tri = max(xlst[i]+1, m+1-sub);
					res = max(res, (xlst[i]-li+1)+(m+1-tri)+(xsum[tri-1]-xsum[xlst[i]]));
				}
				else if (ri == m) {
					int sub = (xlst[i]+rcnt) - ri, tli = min(xlst[i]-1, sub);
					res = max(res, (ri-xlst[i]+1)+tli+(xsum[xlst[i]-1]-xsum[tli]));
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
