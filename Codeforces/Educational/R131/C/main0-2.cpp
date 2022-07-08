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
		vector<int> a(m);
		rep(i, m) {
			cin >> a[i];
			a[i]--;
		}
		vector<int> acnt(n);
		rep(i, m) acnt[a[i]]++;
		sort(acnt.rbegin(), acnt.rend());
		int li = 0, ri = 2*m;
		while (ri-li > 1) {
			int ci = ri - (ri-li) / 2;
			vector<int> tcnt = acnt;
			int rid = n-1;
			bool ok = true;
			rep(lid, n) {
				if (rid <= lid) {
					if (tcnt[lid] > ci) ok = false;
					break;
				}
				while (tcnt[lid] > ci) {
					while (rid>lid && tcnt[rid]+2>ci) --rid;
					if (rid <= lid) {
						ok = false;
						break;
					}
					tcnt[lid]--;
					tcnt[rid] += 2;
				}
				if (!ok) break;
			}
			if (ok) ri = ci;
			else li = ci;
		}
		cout << ri << endl;
	}
	return 0;
}
