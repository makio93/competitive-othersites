// 

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
		vector<int> s(n);
		rep(i, n) cin >> s[i];
		map<int, vector<int>> sids;
		rep(i, n) sids[s[i]].push_back(i);
		bool ok = true;
		vector<int> res;
		for (auto itr=sids.begin(); itr!=sids.end(); ++itr) {
			if ((int)(itr->second.size()) <= 1) {
				ok = false;
				break;
			}
			int m = itr->second.size();
			rep3(i, 1, m) res.push_back(itr->second[i]+1);
			res.push_back(itr->second[0]+1);
		}
		if (ok) rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
		else cout << -1 << endl;
	}
	return 0;
}
