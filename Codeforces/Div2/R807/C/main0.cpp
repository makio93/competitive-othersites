// 

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
		int n, c, q;
		string s;
		cin >> n >> c >> q >> s;
		vector<ll> l(c), r(c);
		rep(i, c) {
			cin >> l[i] >> r[i];
			l[i]--;
		}
		vector<ll> clst;
		clst.push_back(0);
		ll tsum = n;
		rep(i, c) {
			clst.push_back(tsum);
			tsum += r[i] - l[i];
		}
		clst.push_back(tsum);
		rep(i, q) {
			ll k;
			cin >> k;
			--k;
			while (k >= n) {
				int id = upper_bound(all(clst), k) - clst.begin() - 1;
				k = l[id-1] + (k - clst[id]);
			}
			cout << s[(int)k] << endl;
		}
	}
	return 0;
}
