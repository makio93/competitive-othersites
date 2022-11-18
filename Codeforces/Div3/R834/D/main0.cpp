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
		ll n; 
		int m;
		cin >> n >> m;
		int zcnt = 0;
		while (n%10 == 0) {
			n /= 10;
			++zcnt;
		}
		while (n%10%2==0 || n%10==5) {
			if (n%10 == 5) {
				if (m < 2) break;
				n *= 2;
				m /= 2;
			}
			else if (n%10%2 == 0) {
				if (m < 5) break;
				n *= 5;
				m /= 5;
			}
			while (n%10 == 0) {
				n /= 10;
				++zcnt;
			}
		}
		while (m >= 10) {
			++zcnt;
			m /= 10;
		}
		if (m > 0) n *= m;
		string res = to_string(n) + string(zcnt, '0');
		cout << res << endl;
	}
	return 0;
}
