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
		int m, s;
		cin >> m >> s;
		vector<int> b(m);
		rep(i, m) cin >> b[i];
		int mval = *max_element(all(b));
		set<int> blst;
		rep(i, m) blst.insert(b[i]);
		int sum = 0, id = 1;
		while (sum<s || id<=mval) {
			if (blst.find(id) == blst.end()) sum += id;
			++id;
		}
		if (sum == s) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
