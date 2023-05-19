// 本番WA2

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

const int INF = (int)(1e9);
const vector<vector<int>> slst = {
	{ 1, 1, 0 }, { 0, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 }
};

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		vector<int> a(3), b(4);
		rep(i, 3) cin >> a[i];
		rep(i, 4) cin >> b[i];
		vector<int> ord(4), svals;
		iota(all(ord), 0);
		svals.push_back(0);
		rep(i, 3) rep3(j, i+1, 3) svals.push_back(abs(a[i]-a[j]));
		sort(all(svals));
		svals.erase(unique(all(svals)), svals.end());
		ll res = 0;
		do {
			for (const int& sub : svals) rep(i1, 4) {
				ll val = 0;
				auto ta = a;
				rep(i, 4) {
					{
						int mcnt = sub;
						rep(j, 3) if (slst[i1][j] == 1) mcnt = min(mcnt, ta[j]);
						val += mcnt * (ll)b[i1];
						rep(j, 3) if (slst[i1][j] == 1) ta[j] -= mcnt;
					}
					{
						int mcnt = INF;
						rep(j, 3) if (slst[ord[i]][j] == 1) mcnt = min(mcnt, ta[j]);
						val += mcnt * (ll)b[ord[i]];
						rep(j, 3) if (slst[ord[i]][j] == 1) ta[j] -= mcnt;
					}
				}
				res = max(res, val);
			}
		} while (next_permutation(all(ord)));
		cout << res << endl;
	}
	return 0;
}
