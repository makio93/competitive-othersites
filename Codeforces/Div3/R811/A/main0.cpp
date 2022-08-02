// 自力AC

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
		int n, h, w;
		cin >> n >> h >> w;
		int sval = h * 60 + w;
		vector<int> tvals;
		rep(i, n) {
			int hi, wi;
			cin >> hi >> wi;
			tvals.push_back(hi*60+wi);
		}
		sort(all(tvals));
		tvals.push_back(tvals[0]+24*60);
		int nval = *lower_bound(all(tvals), sval) - sval;
		int hval = nval / 60, wval = nval % 60;
		cout << hval << ' ' << wval << endl;
	}
	return 0;
}
