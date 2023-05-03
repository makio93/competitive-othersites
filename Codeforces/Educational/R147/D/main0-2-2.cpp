// 本番WA2-2

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
		int n, k;
		cin >> n >> k;
		vector<int> l(n), r(n);
		rep(i, n) cin >> l[i];
		rep(i, n) cin >> r[i];
		int dsum = 0;
		rep(i, n) dsum += r[i] - l[i] + 1;
		if (dsum < k) {
			cout << -1 << endl;
			continue;
		}
		int ncnt = 0, bsum = 0, scnt = 0;
		rep(i, n) {
			if (k <= bsum+r[i]-l[i]+1) break;
			if (r[i]-l[i]+1 == 1) ++scnt;
			bsum += r[i] - l[i] + 1;
			++ncnt;
		}
		int sub = (r[ncnt] - l[ncnt] + 1) - (k-bsum), res = (ncnt+1) * 2 + (l[ncnt]-1) + (k-bsum) - min(sub, scnt);
		scnt -= sub;
		int lid = ncnt;
		while (scnt>0 && lid+1<n) {
			++lid;
			if (r[lid]-l[lid]+1 == 1) ++scnt;
			++ncnt;
			sub = min(scnt, r[lid]-l[lid]+1);
			ncnt -= sub;
			res = min(res, (ncnt+1)*2+(l[lid]-1)+sub);
			scnt -= sub;
		}
		cout << res << endl;
	}
	return 0;
}
