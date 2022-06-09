// 自力WA1

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
	while (1) {
		ll p;
		cin >> p;
		if (p == 0) break;
		ll val = 1;
		while (val*val*val < p) ++val;
		ll res = val * 3;
		if (val*val*(val-1) >= p) res = min(res, val*3-1);
		if (val*(val-1)*(val-1) >= p) res = min(res, val+(val-1)*2);
		cout << res << endl;
	}
	return 0;
}
