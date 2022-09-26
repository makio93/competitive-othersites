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
		int n, c;
		cin >> n >> c;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		unordered_map<int, int> acnt;
		rep(i, n) acnt[a[i]]++;
		int res = 0;
		for (auto& pi : acnt) res += min(pi.second, c);
		cout << res << endl;
	}
	return 0;
}
