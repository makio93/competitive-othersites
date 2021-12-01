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
		int x1, p1, x2, p2;
		cin >> x1 >> p1 >> x2 >> p2;
		int len1 = to_string(x1).length() + p1, len2 = to_string(x2).length() + p2;
		if (len1 > len2) cout << '>' << endl;
		else if (len1 < len2) cout << '<' << endl;
		else {
			int d1 = to_string(x1).length(), d2 = to_string(x2).length();
			if (d1 > d2) {
				rep(i, d1-d2) x2 *= 10;
			}
			else if (d1 < d2) {
				rep(i, d2-d1) x1 *= 10;
			}
			if (x1 > x2) cout << '>' << endl;
			else if (x1 < x2) cout << '<' << endl;
			else cout << '=' << endl;
		}
	}
	return 0;
}
