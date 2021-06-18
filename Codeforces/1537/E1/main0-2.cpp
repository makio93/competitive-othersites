#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番終了後、自力考察で書き直し、AC

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string res(k, (char)(s.front()));
	rep3(i, 2, min(n,k)+1) {
		string tar, t0 = s.substr(0, i);
		int len = 0;
		while (len < k) {
			tar += t0;
			len += i;
		}
		res = min(res, tar.substr(0, k));
	}
	cout << res << endl;
	return 0;
}
