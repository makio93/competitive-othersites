// 解説AC0

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
		vector<map<ll, int>> acnt(1);
		ll asum = 0;
		vector<ll> blst;
		rep(i, n) {
			if (a[i] == 0) {
				acnt.push_back(map<ll, int>());
				blst.push_back(asum);
			}
			else {
				asum += a[i];
				acnt.back()[asum]++;
			}
		}
		int res = acnt[0][0], m = acnt.size();
		rep3(i, 1, m) {
			int mval = 0;
			for (const auto& pi : acnt[i]) mval = max(mval, pi.second);
			res += max(acnt[i][blst[i-1]]+1, mval);
		}
		cout << res << endl;
	}
	return 0;
}
