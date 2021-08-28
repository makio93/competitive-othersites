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
	int t;
	cin >> t;
	rep(i1, t) {
		int n, m, xi, yi;
		cin >> n >> m >> xi >> yi;
		int area = 0;
		if (xi<=n/2 && yi<=m/2) area = 1;
		if (xi>n-n/2 && yi>m-m/2) area = 1;
		if (area == 0) {
			cout << 1 << ' ' << 1 << ' ' << n << ' ' << m << endl;
		}
		else {
			cout << n << ' ' << 1 << ' ' << 1 << ' ' << m << endl;
		}
	}
	return 0;
}
