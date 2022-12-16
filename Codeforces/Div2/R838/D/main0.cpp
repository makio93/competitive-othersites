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
		if (n == 2) {
			cout << "! " << 1 << ' ' << 2 << endl;
			cout.flush();
			int tval = 0;
			cin >> tval;
			if (tval == -1) return 0;
			continue;
		}
		set<int> ids;
		rep3(i, 1, n+1) ids.insert(i);
		map<int, set<int>> rvals;
		pair<int, int> res = { -1, -1 };
		while ((int)(ids.size()) >= 3) {
			int sid = *ids.begin();
			for (auto itr=next(ids.begin()); itr!=ids.end(); ++itr) {
				cout << "? " << sid << ' ' << (*itr) << endl;
				cout.flush();
				int gval = 0;
				cin >> gval;
				if (gval == -1) return 0;
				if (gval > (n-1)/2) {
					res = { sid, (*itr) };
					break;
				}
				rvals[gval].insert(*itr);
			}
			if (res.first != -1) break;
			if ((int)(rvals.rbegin()->second.size()) <= 2) {
				if ((int)(rvals.rbegin()->second.size()) == 1) res = { sid, *rvals.rbegin()->second.begin() };
				else res = { *rvals.rbegin()->second.begin(), *next(rvals.rbegin()->second.begin()) };
				break;
			}
			ids = rvals.rbegin()->second;
			rvals.clear();
		}
		cout << "! " << res.first << ' ' << res.second << endl;
		cout.flush();
		int tval = 0;
		cin >> tval;
		if (tval == -1) return 0;
	}
	return 0;
}
