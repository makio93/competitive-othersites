// 終了後,ヒント有,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		int bcnt = 0;
		for (char ci : s) if (ci == '1') ++bcnt;
		if (bcnt%2==1 || bcnt==0) {
			cout << "NO" << endl;
			continue;
		}
		vector<pair<int, int>> res;
		if (bcnt == n) rep3(i, 2, n+1) res.emplace_back(1, i);
		else {
			int zid = 0;
			while (s[zid]=='0' && zid+1<n) ++zid;
			while (s[zid%n] == '1') ++zid;
			zid %= n;
			rep3(i, 1, n) {
				if (s[(zid+i)%n] == '1') {
					if (s[(zid+i-1)%n] == '1') res.emplace_back(zid+1, (zid+i)%n+1);
					else res.emplace_back((zid+i-1)%n+1, (zid+i)%n+1);
				}
				else {
					if (s[(zid+i-1)%n] == '1') res.emplace_back(zid+1, (zid+i)%n+1);
					else res.emplace_back((zid+i-1)%n+1, (zid+i)%n+1);
				}
			}
		}
		cout << "YES" << endl;
		rep(i, n-1) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
