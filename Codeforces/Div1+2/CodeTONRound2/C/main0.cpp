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
		int n, m;
		cin >> n >> m;
		vector<int> a(m);
		rep(i, m) {
			cin >> a[i];
			a[i]--;
		}
		sort(all(a));
		a.push_back(a[0]+n);
		vector<int> rlst;
		rep(i, m) if (a[i+1]-a[i] > 1) rlst.push_back(a[i+1]-a[i]-1);
		int res = n;
		if (rlst.empty()) {
			cout << res << endl;
			continue;
		}
		sort(rlst.rbegin(), rlst.rend());
		int rlen = rlst.size();
		rep(i, rlen) {
			int sub = i*2 + i*2+1;
			if (sub == rlst[i]) res--;
			else if (sub > rlst[i]) break;
			else res -= rlst[i] - sub;
		}
		cout << res << endl;
	}
	return 0;
}
