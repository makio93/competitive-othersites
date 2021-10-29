#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll n, k;
		cin >> n >> k;
		ll nval = 1, res = 0;
		while (nval < n) {
			if (nval < k) nval *= 2;
			else {
				res += (n-nval+k-1) / k;
				nval = n;
				break;
			}
			++res;
		}
		cout << res << endl;
	}
	return 0;
}
