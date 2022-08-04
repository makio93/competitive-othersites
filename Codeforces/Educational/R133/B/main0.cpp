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
		vector<int> per(n);
		iota(all(per), 1);
		cout << n << endl;
		rep(i, n) cout << per[i] << (i<n-1?' ':'\n');
		repr(i, n-1) {
			swap(per[i], per[i+1]);
			rep(j, n) cout << per[j] << (j<n-1?' ':'\n');
		}
	}
	return 0;
}
