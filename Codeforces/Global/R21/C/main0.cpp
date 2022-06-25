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
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		int k;
		cin >> k;
		vector<int> b(k);
		rep(i, k) cin >> b[i];
		vector<pair<int, ll>> arun, brun, ato, bto;
		arun.emplace_back(a[0], 1);
		rep3(i, 1, n) {
			if (arun.back().first == a[i]) arun.back().second++;
			else arun.emplace_back(a[i], 1);
		}
		for (auto pi : arun) {
			int val = pi.first;
			ll cnt = pi.second;
			while (val%m == 0) {
				val /= m;
				cnt *= m;
			}
			if (!ato.empty() && ato.back().first == val) ato.back().second += cnt;
			else ato.emplace_back(val, cnt);
		}
		brun.emplace_back(b[0], 1);
		rep3(i, 1, k) {
			if (brun.back().first == b[i]) brun.back().second++;
			else brun.emplace_back(b[i], 1);
		}
		for (auto pi : brun) {
			int val = pi.first;
			ll cnt = pi.second;
			while (val%m == 0) {
				val /= m;
				cnt *= m;
			}
			if (!bto.empty() && bto.back().first == val) bto.back().second += cnt;
			else bto.emplace_back(val, cnt);
		}
		if (ato == bto) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
