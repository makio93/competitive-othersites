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
	int n;
	cin >> n;
	int res = 0;
	while (n > 1) {
		int k = -1;
		for (int i=2; i*i<=n; ++i) if (n%i == 0) {
			k = i;
			break;
		}
		if (k == -1) k = n;
		res += k;
		n /= k;
	}
	cout << res << endl;
	return 0;
}
