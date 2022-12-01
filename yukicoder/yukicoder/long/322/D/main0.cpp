#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> w(n);
	rep(i, n) cin >> w[i];
	ll s = 0;
	rep(i, n) s += w[i];
	vector<int> res(n);
	if (s > 0) rep(i, n) res[i] = (int)((ll)w[i]*m/s);
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
