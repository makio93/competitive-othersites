// 本番WA

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
		vector<ll> a(n), b(n+1);
		rep(i, n) cin >> a[i];
		rep(i, n) b[i+1] = b[i] + a[i];
		vector<int> zid;
		rep(i, n) if (a[i] == 0) zid.push_back(i+1);
		int m = zid.size();
		if (m == 0) {
			int res = count(b.begin()+1, b.end(), 0LL);
			cout << res << endl;
			continue;
		}
		else if (m == 1) {
			map<ll, int> bcnt;
			rep3(i, zid[0]+1, n+1) bcnt[b[i]]++;
			int lcnt = 0;
			rep3(i, 1, zid[0]) if (b[i] == 0) ++lcnt;
			int res = lcnt + bcnt[b[zid[0]]] + 1;
			int mval = 0;
			for (const auto& pi : bcnt) mval = max(mval, pi.second);
			res = max(res, lcnt+mval);
			cout << res << endl;
			continue;
		}
		else {
			int mval = 0;
			rep3(i, 1, m-1) {
				map<ll, int> bcnt;
				rep3(j, zid[i]+1, zid[i+1]) bcnt[b[j]]++;
				int tval = 0;
				for (const auto& pi : bcnt) tval = max(tval, pi.second);
				mval += tval;
			}
			{
				map<ll, int> bcnt;
				rep3(j, zid[m-1]+1, n+1) bcnt[b[j]]++;
				int tval = 0;
				for (const auto& pi : bcnt) tval = max(tval, pi.second);
				mval += tval;
			}
			map<ll, int> bcnt;
			rep3(i, zid[0]+1, n+1) bcnt[b[i]]++;
			int lcnt = 0;
			rep3(i, 1, zid[0]) if (b[i] == 0) ++lcnt;
			int res = lcnt + bcnt[b[zid[0]]] + 1 + mval;
			int tval = 0;
			for (const auto& pi : bcnt) tval = max(tval, pi.second);
			res = max(res, lcnt+tval+mval);
			cout << res << endl;
		}
	}
	return 0;
}
