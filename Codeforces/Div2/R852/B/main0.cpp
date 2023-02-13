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
		int x, y;
		cin >> x >> y;
		vector<int> res;
		rep3r(i, y+1, x+1) res.push_back(i);
		rep3(i, y, x) res.push_back(i);
		int n = res.size();
		cout << n << endl;
		rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	}
	return 0;
}
