// 解説AC

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
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> res;
	rep3(i, 1, (int)(2e5)+1) {
		ll tval = i * (ll)a;
		if (tval-b > 0) tval -= b;
		if (tval == c) res.push_back(i);
	}
	if (res.empty()) cout << -1 << endl;
	else for (const int& vi : res) cout << vi << endl;
	return 0;
}
