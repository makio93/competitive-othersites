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
		cin >> n >> x >> y;
		if (x > y) swap(x, y);
		if (x!=0 || (x==0&&y==0) || (n-1)%y!=0) {
			cout << -1 << endl;
			continue;
		}
		int id = (n+1-y);
		vector<int> res;
		while (id > 1) {
			rep(i, y) res.push_back(id);
			id -= y;
		}
		reverse(all(res));
		rep(i, n-1) cout << res[i] << (i<n-2?' ':'\n');
	}
	return 0;
}
