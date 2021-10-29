#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,未完成

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		rep(i, n) rep(j, m) cin >> a[i][j];
		vector<map<int, int>> lcnt, rcnt;
		repr(j, m) rep(i, n) rcnt[i][a[i][j]]++;
		bool ok = false;
		string sres;
		int ires = -1;
		rep(j, m-1) {
			rep(i, n) lcnt[i][a[i][j]]++;
			rep(i, n) {
				rcnt[i][a[i][j]]--;
				if (rcnt[i][a[i][j]] == 0) rcnt[i].erase(a[i][j]);
			}
			vector<pair<int, int>> la, lb, ra, rb;
			rep(i, n) {
				la.emplace_back(lcnt[i].begin()->first, i);
				lb.emplace_back(lcnt[i].rbegin()->first, i);
				ra.emplace_back(rcnt[i].begin()->first, i);
				rb.emplace_back(rcnt[i].rbegin()->first, i);
			}
			sort(all(la));
			sort(all(lb));
			sort(all(ra));
			sort(all(rb));
			bool ok2 = true;
			for (auto pi : lcnt.rbegin()->second) if (rcnt.rbegin()->second.find(pi.first) != rcnt.rbegin()->second.end()) {
				ok2 = false;
				break;
			}
			if (ok2) {
				ok = true;
				ires = j+1;
				rep(i, n) {
					if (lcnt.rbegin()->second.find(i) != lcnt.rbegin()->second.end()) sres.push_back('R');
					else sres.push_back('B');
				}
				break;
			}
			else {
				rep(i, n) lcnt[a[i][j+1]][i]++;
				rep(i, n) {
					rcnt[a[i][j+1]][i]--;
					if (rcnt[a[i][j+1]][i] == 0) rcnt[a[i][j+1]].erase(i);
					if (rcnt[a[i][j+1]].empty()) rcnt.erase(a[i][j+1]);
				}
			}
		}
		if (ok) {
			cout << "YES" << endl;
			cout << sres << ' ' << ires << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
