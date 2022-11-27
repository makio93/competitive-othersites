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
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		vector<pair<int, int>> alst;
		alst.emplace_back(a[0], 1);
		rep3(i, 1, n) {
			if (alst.back().first == a[i]) alst.back().second++;
			else alst.emplace_back(a[i], 1);
		}
		ll res = 0;
		int sum = 0, m = alst.size();
		if (m > 1) {
			rep(i, m-1) {
				sum += alst[i].second;
				res = max(res, (ll)sum*(n-sum));
			}
		}
		else res = n / 2;
		cout << res << endl;
	}
	return 0;
}
