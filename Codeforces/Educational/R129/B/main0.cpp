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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		cin >> m;
		vector<int> b(m);
		rep(i, m) cin >> b[i];
		int id = 0;
		rep(i, m) id = (id + b[i]) % n;
		cout << a[id] << endl;
	}
	return 0;
}
