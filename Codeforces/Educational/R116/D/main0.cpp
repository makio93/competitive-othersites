#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA

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
		map<int, unordered_map<int, int>> lcnt, rcnt;
		rep3r(j, 1, m) rep(i, n) rcnt[a[i][j]][i]++;
		rep(i, n) lcnt[a[i][0]][i]++;
		bool ok = false;
		string sres;
		int ires = -1;
		rep(j, m-1) {
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
