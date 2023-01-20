// 解説AC

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
const ll mod = 998244353LL;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> xlst;
	rep(i, n) {
		int li, ri;
		cin >> li >> ri;
		xlst.emplace_back(li, 1);
		xlst.emplace_back(ri, -1);
	}
	sort(all(xlst));
	int tcnt = 0;
	ll sub = 1;
	for (const auto& pi : xlst) {
		if (pi.second == 1) {
			sub = sub * max(0, k-tcnt) % mod;
			++tcnt;
		}
		else --tcnt;
	}
	ll res = 1;
	rep(i, n) res = res * k % mod;
	res = (res - sub + mod) % mod;
	cout << res << endl;
	return 0;
}
