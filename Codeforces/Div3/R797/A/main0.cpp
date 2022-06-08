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
		int n;
		cin >> n;
		int h = (n-3) / 3, r = n - h * 3;
		vector<int> res(3, h);
		if ((n-3)%3 == 0) { res[0]++; res[1] += 2; }
		else if ((n-3)%3 == 1) { res[0]++; res[1] += 3; }
		else if ((n-3)%3 == 2) { res[0] += 2; res[1] += 3; }
		rep(i, 3) cout << res[i] << (i<2?' ':'\n');
	}
	return 0;
}
