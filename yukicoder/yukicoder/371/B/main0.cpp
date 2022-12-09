// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> sub(n+1);
	rep(i, m) {
		int li, ri;
		cin >> li >> ri;
		li = -li + n, ri = -ri + n + 1;
		sub[li]++;
		sub[ri]--;
	}
	rep(i, n) sub[i+1] += sub[i];
	rep(i, n) cout << sub[i] << endl;
	return 0;
}
