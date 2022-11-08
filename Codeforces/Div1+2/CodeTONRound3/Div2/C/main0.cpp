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
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector<int> ids;
		bool ok = true;
		rep(i, n-1) {
			if ((a[i+1]!=a[i]) ^ (b[i+1]!=b[i])) {
				ok = false;
				break;
			}
			if (a[i+1]==a[i] && b[i+1]==b[i]) continue;
			ids.push_back(i);
		}
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		vector<pair<int, int>> res;
		if (ids.empty()) {
			ids.push_back(0);
			a[0] = (char)((1-(a[0]-'0')) + '0');
			rep3(i, 1, n) b[i] = (char)((1-(b[i]-'0')) + '0');
			res.emplace_back(1, 1);
		}
		bool left = (b[n-1] == '1'), last = (a[0] == '1');
		if (left) last = !last;
		int m = ids.size();
		rep(i, m) {
			if (i==m-1 && left) res.emplace_back(1, ids[i]+1);
			else res.emplace_back(ids[i]+2, n);
		}
		if (last) res.emplace_back(1, n);
		int k = res.size();
		cout << "YES" << endl;
		cout << k << endl;
		rep(i, k) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
