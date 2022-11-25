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
		int n, x;
		cin >> n >> x;
		if (n%x != 0) {
			cout << -1 << endl;
			continue;
		}
		int mval = n / x;
		vector<int> plst;
		for (int i=2; i*i<=mval; ++i) {
			while (mval%i == 0) {
				plst.push_back(i);
				mval /= i;
			}
		}
		if (mval > 1) plst.push_back(mval);
		sort(all(plst));
		int m = plst.size();
		vector<int> res(n);
		iota(all(res), 1);
		res[0] = x;
		res[n-1] = 1;
		int id = x;
		rep(i, m) {
			res[id-1] = id * plst[i];
			id *= plst[i];
		}
		rep(i, n) cout << res[i] << ' ';
		cout << endl;
	}
	return 0;
}
