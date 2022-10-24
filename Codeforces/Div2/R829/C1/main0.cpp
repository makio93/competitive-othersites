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
		if (n%2 == 1) {
			cout << -1 << endl;
			continue;
		}
		vector<pair<int, int>> res;
		int sum = 0;
		int li = -1;
		rep(i, n) {
			if (li == -1) {
				sum += a[i];
				li = i;
				res.emplace_back(i+1, -1);
			}
			else {
				int add = a[i];
				if ((i-li+1)%2 == 0) {
					add *= -1;
					if (sum+add == 0) sum += add;
					else {
						res.back().second = i;
						sum += a[i];
						li = i;
						res.emplace_back(i+1, -1);
					}
				}
				else sum += a[i];
			}
			if (i == n-1) res.back().second = i+1;
		}
		int klen = res.size();
		cout << klen << endl;
		rep(i, klen) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
