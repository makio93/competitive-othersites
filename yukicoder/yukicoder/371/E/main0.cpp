// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1.5e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(n, vector<int>(m));
	rep(i, n) {
		rep(j, m) cin >> d[i][j];
		sort(all(d[i]));
	}
	int lval = -1, rval = INF;
	while (rval-lval > 1) {
		int cval = lval + (rval-lval) / 2;
		vector<int> dist(m+1), ndist;
		rep(i, m) dist[i] = 1;
		rep(i, n-1) {
			ndist.assign(m+1, 0);
			rep(j, m) if (dist[j] > 0) {
				int di = d[i][j], ndi = di + cval;
				int li = lower_bound(all(d[i+1]), di) - d[i+1].begin(), ri = upper_bound(all(d[i+1]), ndi) - d[i+1].begin();
				ndist[li]++, ndist[ri]--;
			}
			rep(j, m) ndist[j+1] += ndist[j];
			swap(ndist, dist);
		}
		int vcnt = 0;
		rep(i, m) if (dist[i] > 0) ++vcnt;
		if (vcnt > 0) rval = cval;
		else lval = cval;
	}
	if (rval == INF) cout << -1 << endl;
	else cout << rval << endl;
	return 0;
}
