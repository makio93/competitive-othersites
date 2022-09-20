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
		int n, x, y;
		string a, b;
		cin >> n >> x >> y >> a >> b;
		vector<int> ids;
		rep(i, n) if (a[i] != b[i]) ids.push_back(i);
		if ((int)(ids.size())%2 == 1) {
			cout << -1 << endl;
			continue;
		}
		ll res = 0;
		if ((int)(ids.size())==2 && ids[0]+1==ids[1]) res = min((ll)y*2, (ll)x);
		else res = (int)(ids.size()) / 2 * (ll)y;
		cout << res << endl;
	}
	return 0;
}
