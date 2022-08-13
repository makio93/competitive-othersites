// 本番WA1

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
		int n, k;
		cin >> n >> k;
		if (n == k) {
			cout << INF << endl;
			continue;
		}
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		sort(all(a));
		rep(i, k) a[i] = INF;
		sort(all(a));
		cout << min(INF, a[0]*2) << endl;
	}
	return 0;
}
