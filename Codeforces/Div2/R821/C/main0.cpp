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
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		int tval = a[0] % 2, id = n;
		repr(i, n) if (a[i]%2 == tval) {
			id = i;
			break;
		}
		vector<pair<int, int>> res;
		int pid = n;
		while (1) {
			rep3(i, id+1, pid) {
				a[i] = a[id];
				res.emplace_back(id+1, i+1);
			}
			if (id == 0) break;
			repr(i, id) if (a[i]%2 == tval) {
				res.emplace_back(i+1, id+1);
				pid = id;
				id = i;
				break;
			}
		}
		int mlen = res.size();
		cout << mlen << endl;
		rep(i, mlen) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
